#include <SFML/Graphics.hpp>
#include "AStar.h"
#include "GameCharacter.h"

// Funzione per verificare se un nodo è nel percorso
bool isNodeInPath(Node* node, const std::vector<Node*>& path) {
    return std::find(path.begin(), path.end(), node) != path.end();
}
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Node.h"
#include "GameCharacter.h"
#include "AStar.h"

int main() {
    const int gridWidth = 20;
    const int gridHeight = 20;
    const int cellSize = 32;

    // Define obstacles
    std::vector<std::pair<int, int>> obstacles = {{1, 1}, {2, 2}, {3, 3}, {5, 5}, {7, 8}, {7, 14}};

    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "A* Pathfinding");

    Grid grid(gridWidth, gridHeight, obstacles);
    Node& startNode = grid.nodes[0][0];
    Node& endNode = grid.nodes[19][19];

    GameCharacter character(&startNode);
    std::vector<Node*> path = AStar::findPath(grid, startNode, endNode);
    character.setPath(path);

    sf::Clock clock; // For tracking time
    const float moveInterval = 1.0f; // Time interval in seconds for moving the character

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Check if it's time to move
        if (clock.getElapsedTime().asSeconds() >= moveInterval) {
            if (!character.hasReachedDestination()) {
                character.move();
            }
            clock.restart(); // Restart the clock after moving
        }

        window.clear();

        for (int x = 0; x < gridWidth; ++x) {
            for (int y = 0; y < gridHeight; ++y) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(x * cellSize, y * cellSize);

                Node* currentNode = &grid.nodes[x][y];
                sf::Color cellColor = sf::Color::White; // Default color

                if (currentNode->isObstacle) {
                    cellColor = sf::Color::Black; // Obstacle color
                } else if (currentNode == character.getCurrentNode()) {
                    cellColor = sf::Color::Green; // Character position
                } else if (currentNode == &endNode) {
                    cellColor = sf::Color::Red; // End position
                } else if (isNodeInPath(currentNode, character.getPath())) {
                    cellColor = sf::Color::White; // Path
                }

                cell.setFillColor(cellColor);
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}

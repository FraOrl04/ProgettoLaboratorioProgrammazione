#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
// Funzione per verificare se un nodo è nel percorso
bool isNodeInPath(Node* node, const std::vector<Node*>& path) {
    return std::find(path.begin(), path.end(), node) != path.end();
}


int main() {
    const int gridWidth = 20;
    const int gridHeight = 20;
    const int cellSize = 32;

    // Define obstacles
    std::vector<std::pair<int, int>> obstacles = {{1, 1}, {2, 2}, {3, 3},{5,0}, {5, 1},{5, 2},{5, 3},{5, 4},{5, 5},{5, 6},{5, 7},{6,18},{10,19}};

    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "A* Pathfinding");

    Grid grid(gridWidth, gridHeight, obstacles);
    Node& startNode = grid.nodes1()[0][0];
    Node& endNode = grid.nodes1()[gridWidth-1][gridHeight-1]; // Corretto per accedere all'angolo in basso a destra


    GameCharacter character(&startNode);
    std::vector<Node*> path = GameCharacter::findPath(grid, startNode, endNode);
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

                Node* currentNode = &grid.nodes1()[x][y];
                sf::Color cellColor = sf::Color::White; // Default color

                if (currentNode->get_is_obstacle()) {
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

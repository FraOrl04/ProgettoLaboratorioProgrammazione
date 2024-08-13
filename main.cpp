#include <SFML/Graphics.hpp>
#include "AStar.h"
#include "GameCharacter.h"

// Funzione per verificare se un nodo è nel percorso
bool isNodeInPath(Node* node, const std::vector<Node*>& path) {
    return std::find(path.begin(), path.end(), node) != path.end();
}

int main() {
    const int gridWidth = 20;
    const int gridHeight = 20;
    const int cellSize = 32;

    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "A* Pathfinding");

    Grid grid(gridWidth, gridHeight);
    Node& startNode = grid.nodes[0][0];
    Node& endNode = grid.nodes[19][19];

    GameCharacter character(&startNode);
    std::vector<Node*> path = AStar::findPath(grid, startNode, endNode);
    character.setPath(path);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controlla se il tasto spazio è premuto e aggiorna la posizione del personaggio
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!character.hasReachedDestination()) {
                character.move();
            }
        }

        window.clear();

        // Disegna la griglia
        for (int x = 0; x < gridWidth; ++x) {
            for (int y = 0; y < gridHeight; ++y) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(x * cellSize, y * cellSize);

                Node* currentNode = &grid.nodes[x][y];
                sf::Color cellColor = sf::Color::White; // Colore di default

                if (currentNode == character.getCurrentNode()) {
                    cellColor = sf::Color::Green; // Posizione corrente del personaggio
                } else if (currentNode == &endNode) {
                    cellColor = sf::Color::Red; // Destinazione
                } else if (isNodeInPath(currentNode, character.getPath())) {
                    cellColor = sf::Color::White; // Percorso
                }

                cell.setFillColor(cellColor);
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}


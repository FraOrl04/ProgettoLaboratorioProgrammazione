//
// Created by fra on 13/08/24.
//

#include "Grid.h"
Grid::Grid(int width, int height) : width(width), height(height) {
    for (int x = 0; x < width; ++x) {
        std::vector<Node> column;
        for (int y = 0; y < height; ++y) {
            column.push_back(Node(x,y));
        }
        nodes.push_back(column);
    }
}

std::vector<Node *> Grid::getNeighbors(Node &node) {
    std::vector<Node*> neighbors;

    if (node.x - 1 >= 0) neighbors.push_back(&nodes[node.x - 1][node.y]); // Sinistra
    if (node.x + 1 < width) neighbors.push_back(&nodes[node.x + 1][node.y]); // Destra
    if (node.y - 1 >= 0) neighbors.push_back(&nodes[node.x][node.y - 1]); // Su
    if (node.y + 1 < height) neighbors.push_back(&nodes[node.x][node.y + 1]); // Giù

    return neighbors;
}

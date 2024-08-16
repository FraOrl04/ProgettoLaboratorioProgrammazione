//
// Created by fra on 13/08/24.
//

#include "Grid.h"
Grid::Grid(int width, int height, const std::vector<std::pair<int, int>>& obstacles)
    : width(width), height(height) {
    for (int x = 0; x < width; ++x) {
        std::vector<Node> column;
        for (int y = 0; y < height; ++y) {
            bool isObstacle = std::find(obstacles.begin(), obstacles.end(), std::make_pair(x, y)) != obstacles.end();
            column.push_back(Node(x, y, isObstacle));
        }
        nodes.push_back(column);
    }
}

std::vector<Node*> Grid::getNeighbors(Node& node) {
    std::vector<Node*> neighbors;

    if (node.x - 1 >= 0 && !nodes[node.x - 1][node.y].isObstacle)
        neighbors.push_back(&nodes[node.x - 1][node.y]); // Sinistra
    if (node.x + 1 < width && !nodes[node.x + 1][node.y].isObstacle)
        neighbors.push_back(&nodes[node.x + 1][node.y]); // Destra
    if (node.y - 1 >= 0 && !nodes[node.x][node.y - 1].isObstacle)
        neighbors.push_back(&nodes[node.x][node.y - 1]); // Su
    if (node.y + 1 < height && !nodes[node.x][node.y + 1].isObstacle)
        neighbors.push_back(&nodes[node.x][node.y + 1]); // Giù

    return neighbors;
}

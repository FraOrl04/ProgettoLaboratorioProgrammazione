#include "Grid.h"



int Grid::get_width() const {
    return width;
}

int Grid::get_height() const {
    return height;
}

std::vector<std::vector<Node>>& Grid::Access_Node() {
    return nodes;
}

Grid::Grid(int width, int height, const std::vector<std::pair<int, int>>& obstacles)
    : width(width), height(height) {
    //il costruttore lancia un eccezione quando le dimensioni della griglia sono nulle o negative
    // oppure se gli ostacoli hanno posizione negativa
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Le dimensioni della griglia devono essere maggiori di zero.");
    }

    for (const auto& obs : obstacles) {
        if (obs.first < 0 || obs.second < 0) {
            throw std::invalid_argument("Le coordinate degli ostacoli non possono essere negative.");
        }
    }

    for (int x = 0; x < width; ++x) {
        std::vector<Node> column;
        for (int y = 0; y < height; ++y) {
            bool isObstacle = std::find(obstacles.begin(), obstacles.end(), std::make_pair(x, y)) != obstacles.end();
            column.push_back(Node(x, y, isObstacle));
        }
        nodes.push_back(column);
    }
}


std::vector<Node*> Grid::AccesNodeNeigthbors(Node& node) {
    std::vector<Node*> neighbors;

    if (node.get_x() - 1 >= 0 && !nodes[node.get_x() - 1][node.get_y()].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x() - 1][node.get_y()]); // Sinistra
    if (node.get_x() + 1 < width && !nodes[node.get_x() + 1][node.get_y()].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x() + 1][node.get_y()]); // Destra
    if (node.get_y() - 1 >= 0 && !nodes[node.get_x()][node.get_y() - 1].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x()][node.get_y() - 1]); // Su
    if (node.get_y() + 1 < height && !nodes[node.get_x()][node.get_y() + 1].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x()][node.get_y() + 1]); // Giù

    return neighbors;
}

bool Grid::isNodeInPath(Node* node, const std::vector<Node*>& path) const {
    return std::find(path.begin(), path.end(), node) != path.end();
}




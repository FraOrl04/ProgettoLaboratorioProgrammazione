#include "Grid.h"

void Grid::set_nodes(const std::vector<std::vector<Node>>& newNodes) {
    if (newNodes.size() != width || (newNodes.size() > 0 && newNodes[0].size() != height)) {
        throw std::invalid_argument("Il nuovo nodo non coincide con le dimensioni della griglia");
    }
    nodes = newNodes;
}

int Grid::width1() const {
    return width;
}

int Grid::height1() const {
    return height;
}

std::vector<std::vector<Node>>& Grid::nodes1() {
    return nodes;
}

Grid::Grid(int width, int height, const std::vector<std::pair<int, int>>& obstacles)
    : width(width), height(height) {
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


std::vector<Node*> Grid::getNeighbors(Node& node) {
    std::vector<Node*> neighbors;

    if (node.get_x1() - 1 >= 0 && !nodes[node.get_x1() - 1][node.get_y1()].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x1() - 1][node.get_y1()]); // Sinistra
    if (node.get_x1() + 1 < width && !nodes[node.get_x1() + 1][node.get_y1()].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x1() + 1][node.get_y1()]); // Destra
    if (node.get_y1() - 1 >= 0 && !nodes[node.get_x1()][node.get_y1() - 1].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x1()][node.get_y1() - 1]); // Su
    if (node.get_y1() + 1 < height && !nodes[node.get_x1()][node.get_y1() + 1].get_is_obstacle())
        neighbors.push_back(&nodes[node.get_x1()][node.get_y1() + 1]); // Giù

    return neighbors;
}




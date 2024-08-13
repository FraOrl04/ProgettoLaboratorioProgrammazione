//
// Created by fra on 13/08/24.
//

#ifndef GRID_H
#define GRID_H
#include <vector>
#include "Node.h"

class Grid {
public:
    int width, height;
    std::vector<std::vector<Node>> nodes;

    Grid(int width, int height);

    std::vector<Node*> getNeighbors(Node& node);
};

#endif //GRID_H

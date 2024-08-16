//
// Created by fra on 13/08/24.
//

#ifndef GRID_H
#define GRID_H
#include <vector>
#include "Node.h"
#include<algorithm>

class Grid {
public:
    int width, height;
    std::vector<std::vector<Node>> nodes;

    Grid(int width, int height, const std::vector<std::pair<int, int>>& obstacles = {});

    std::vector<Node*> getNeighbors(Node& node);
};

#endif //GRID_H

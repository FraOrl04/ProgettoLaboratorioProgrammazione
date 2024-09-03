#ifndef GRID_H
#define GRID_H

#include <vector>
#include <utility>
#include "Node.h"
#include<algorithm>
class Grid {
public:
    Grid(int width, int height, const std::vector<std::pair<int, int>>& obstacles);
    int width1() const;
    int height1() const;
    std::vector<std::vector<Node>>& nodes1(); // Changed to return a reference
    void set_nodes(const std::vector<std::vector<Node>>& newNodes);
    std::vector<Node*> getNeighbors(Node& node);

private:
    int width;
    int height;
    std::vector<std::vector<Node>> nodes;
};

#endif // GRID_H

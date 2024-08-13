//
// Created by fra on 13/08/24.
//

#include "Node.h"
#include <cmath>

Node::Node(int x, int y): x(x), y(y), gCost(0), hCost(0), fCost(0), parent(nullptr) {}

void Node::calculateFCost() {
    fCost = gCost + hCost;
}

void Node::calculateHeuristic(const Node &endNode) {
    hCost = abs(x - endNode.x) + abs(y - endNode.y);
}

bool Node::operator<(const Node &other) const {
    return fCost > other.fCost; // Inverted for priority queue (min-heap behavior)
}

bool Node::operator==(const Node &other) const {
    return x == other.x && y == other.y;
}


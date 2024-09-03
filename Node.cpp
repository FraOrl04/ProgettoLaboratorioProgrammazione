#include "Node.h"
#include <cmath>
#include <stdexcept>
Node::Node(int x, int y, bool isObstacle)
    : x(x), y(y), gCost(0), hCost(0), fCost(0), parent(nullptr), isObstacle(isObstacle) {
    if (x < 0 || y < 0) {
        throw std::invalid_argument("Le coordinate del nodo non possono essere negative.");
    }
}


int Node::get_x1() const {
    return x;
}

int Node::get_y1() const {
    return y;
}

bool Node::get_is_obstacle() const {
    return isObstacle;
}

float Node::get_gCost() const {
    return gCost;
}

float Node::get_hCost() const {
    return hCost;
}

float Node::get_fCost() const {
    return fCost;
}

void Node::set_gCost(float gCost) {
    this->gCost = gCost;
}

void Node::set_is_obstacle(bool isObstacle) {
    this->isObstacle = isObstacle;
}

Node* Node::get_parent() const {
    return parent;
}

void Node::set_parent(Node* parent) {
    this->parent = parent;
}

void Node::calculateFCost() {
    fCost = gCost + hCost;
}

void Node::calculateL_distance(const Node& endNode) {
    hCost = std::abs(x - endNode.get_x1()) + std::abs(y - endNode.get_y1());
}

bool Node::operator<(const Node& other) const {
    return fCost < other.fCost;
}

bool Node::operator==(const Node& other) const {
    return x == other.x && y == other.y;
}

#include "GameCharacter.h"

#include <iostream>
#include <stdexcept>

GameCharacter::GameCharacter(Node *startNode) : currentNode(startNode), pathIndex(0) {}

void GameCharacter::setPath(const std::vector<Node *> &path) {
    this->path = path;
    pathIndex = 0;  // Reset pathIndex when setting a new path
    if (!path.empty()) {
        currentNode = path[0];
    }
}

void GameCharacter::move() {
    if (pathIndex < path.size() - 1) { // Check if there are nodes left to move to
        pathIndex++;
        currentNode = path[pathIndex];
    }
}

bool GameCharacter::hasReachedDestination() const {
    return pathIndex == path.size() - 1; // Check if the current node is the last in the path
}

Node* GameCharacter::getCurrentNode() const {
    return currentNode;
}

std::vector<Node*> GameCharacter::getPath() const {
    return path;
}
//Astar
std::vector<Node *> GameCharacter::findPath(Grid &grid, Node &startNode, Node &endNode) {
    auto compare = [](Node* a, Node* b) { return a->get_fCost() > b->get_fCost(); };
    std::priority_queue<Node*, std::vector<Node*>, decltype(compare)> openSet(compare);
    std::unordered_set<Node*> closedSet;
    std::unordered_set<Node*> openSetTracker; // Per tracciare i nodi nell'openSet

    startNode.calculateL_distance(endNode);
    startNode.calculateFCost();
    openSet.push(&startNode);
    openSetTracker.insert(&startNode);

    while (!openSet.empty()) {
        Node* currentNode = openSet.top();
        openSet.pop();
        openSetTracker.erase(currentNode);

        if (*currentNode == endNode) {
            return reconstructPath(currentNode);
        }

        closedSet.insert(currentNode);

        for (auto neighbor : grid.AccesNodeNeigthbors(*currentNode)) {
            if (closedSet.find(neighbor) != closedSet.end()) {
                continue;
            }

            float tentativeGCost = currentNode->get_gCost() + 1;
            if (tentativeGCost < neighbor->get_gCost() || openSetTracker.find(neighbor) == openSetTracker.end()) {
                neighbor->set_gCost(tentativeGCost);
                neighbor->calculateL_distance(endNode);
                neighbor->calculateFCost();
                neighbor->set_parent(currentNode);

                if (openSetTracker.find(neighbor) == openSetTracker.end()) {
                    openSet.push(neighbor);
                    openSetTracker.insert(neighbor);
                }
            }
        }
    }
    std::cerr <<"percorso non trovato: nessun perscorso esistente per il nodo destinazione" << std::endl;
    throw std::runtime_error("percorso non trovato: nessun perscorso esistente per il nodo destinazione");
}

std::vector<Node *> GameCharacter::reconstructPath(Node *endNode) {
    std::vector<Node*> path;
    Node* currentNode = endNode;

    while (currentNode != nullptr) {
        path.push_back(currentNode);
        currentNode = currentNode->get_parent();
    }

    std::reverse(path.begin(), path.end());
    return path;
}

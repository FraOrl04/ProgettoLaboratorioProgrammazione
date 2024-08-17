#include "GameCharacter.h"

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

const std::vector<Node*>& GameCharacter::getPath() const {
    return path;
}

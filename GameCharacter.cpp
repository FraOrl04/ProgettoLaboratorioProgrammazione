//
// Created by fra on 13/08/24.
//

#include "GameCharacter.h"


GameCharacter::GameCharacter(Node *startNode): currentNode(startNode), pathIndex(0) {

}

void GameCharacter::setPath(const std::vector<Node *> &path) {
    this->path = path;
}

void GameCharacter::move() {
    if (pathIndex < path.size()) {
        currentNode = path[pathIndex];
        pathIndex++;
    }
}

bool GameCharacter::hasReachedDestination() const {
    return pathIndex >= path.size();
}

Node * GameCharacter::getCurrentNode() const {
    return currentNode;

}

const std::vector<Node *> & GameCharacter::getPath() const {
    return path;
}

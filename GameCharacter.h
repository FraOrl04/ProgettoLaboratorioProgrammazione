//
// Created by fra on 13/08/24.
//

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include "AStar.h"
#include <vector>

class GameCharacter {
public:
    GameCharacter(Node* startNode);
    void setPath(const std::vector<Node*>& path);
    void move();

    bool hasReachedDestination() const;

    Node* getCurrentNode() const;

    const std::vector<Node*>& getPath() const;

private:
    Node* currentNode;
    std::vector<Node*> path;
    size_t pathIndex;
};

#endif //GAMECHARACTER_H

//
// Created by fra on 13/08/24.
//

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <vector>
#include "Node.h"
#include "Grid.h"
#include <queue>
#include <unordered_set>
#include <functional>
class GameCharacter {
public:
    GameCharacter(Node* startNode);
    void setPath(const std::vector<Node*>& path);
    void move();
    bool hasReachedDestination() const;
    Node* getCurrentNode() const;
    const std::vector<Node*>& getPath() const;
    static std::vector<Node*> findPath(Grid& grid, Node& startNode, Node& endNode);

private:
   static  std::vector<Node*> reconstructPath(Node* endNode);
    Node* currentNode;
    std::vector<Node*> path;
    size_t pathIndex;
};

#endif // GAMECHARACTER_H

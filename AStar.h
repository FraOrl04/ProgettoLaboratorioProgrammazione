//
// Created by fra on 13/08/24.
//

#ifndef ASTAR_H
#define ASTAR_H
#include "Node.h"
#include "Grid.h"
#include <queue>
#include <unordered_set>
#include <functional>

class AStar {
public:
    static std::vector<Node*> findPath(Grid& grid, Node& startNode, Node& endNode) {
        auto compare = [](Node* a, Node* b) { return a->fCost > b->fCost; };
        std::priority_queue<Node*, std::vector<Node*>, decltype(compare)> openSet(compare);
        std::unordered_set<Node*> closedSet;
        std::unordered_set<Node*> openSetTracker; // Per tracciare i nodi nell'openSet

        startNode.calculateHeuristic(endNode);
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

            for (auto neighbor : grid.getNeighbors(*currentNode)) {
                if (closedSet.find(neighbor) != closedSet.end()) {
                    continue;
                }

                float tentativeGCost = currentNode->gCost + 1;
                if (tentativeGCost < neighbor->gCost || openSetTracker.find(neighbor) == openSetTracker.end()) {
                    neighbor->gCost = tentativeGCost;
                    neighbor->calculateHeuristic(endNode);
                    neighbor->calculateFCost();
                    neighbor->parent = currentNode;

                    if (openSetTracker.find(neighbor) == openSetTracker.end()) {
                        openSet.push(neighbor);
                        openSetTracker.insert(neighbor);
                    }
                }
            }
        }

        return std::vector<Node*>(); // Nessun percorso trovato
    }

private:
    static std::vector<Node*> reconstructPath(Node* endNode) {
        std::vector<Node*> path;
        Node* currentNode = endNode;

        while (currentNode != nullptr) {
            path.push_back(currentNode);
            currentNode = currentNode->parent;
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};

#endif //ASTAR_H

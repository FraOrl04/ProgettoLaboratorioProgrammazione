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
    //costruttore GameCharacter
    GameCharacter(Node* startNode);

    //metodo che setta il percorso
    void setPath(const std::vector<Node*>& path);

    // metodo che fa muovere il personaggio sulla mappa
    void move();

    //metodo che restituisce un valore vero se il nodo è arrivato a destinazione
    bool hasReachedDestination() const;

    //metodo che restituisce il nodo corrente
    Node* getCurrentNode() const;

    //metodo che restitusce il percorso dei nodi
     std::vector<Node*> getPath() const;

    //Astar
    static std::vector<Node*> findPath(Grid& grid, Node& startNode, Node& endNode);

private:
    //Astar
   static  std::vector<Node*> reconstructPath(Node* endNode);
    Node* currentNode;
    std::vector<Node*> path;
    size_t pathIndex;
};

#endif // GAMECHARACTER_H

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <utility>
#include "Node.h"
#include<algorithm>
class Grid {
public:
    //costruttore griglia che prende in ingresso le dimensioni e gli ostacoli
    Grid(int width, int height, const std::vector<std::pair<int, int>>& obstacles);

    //metodi getter che restituiscono le dimensioni della griglia
    int get_width() const;
    int get_height() const;

    //metodo che permette l'accesso ai nodi e la creazione
    std::vector<std::vector<Node>>& Access_Node();
    //metodo che permette l'accesso hai vicini di uno specifico nodo
    std::vector<Node*> AccesNodeNeigthbors(Node& node);
    // Funzione per verificare se un nodo è nel percorso
    bool isNodeInPath(Node* node, const std::vector<Node*>& path) const;
private:
    int width;
    int height;
    std::vector<std::vector<Node>> nodes;
};

#endif // GRID_H

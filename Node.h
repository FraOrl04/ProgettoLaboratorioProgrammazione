#ifndef NODE_H
#define NODE_H

#include <cmath>
#include <stdexcept>

class Node {
public:
    //costruttore Nodo
    Node(int x, int y, bool isObstacle=false);

    //metodi getter per le coordinate del nodo
    int get_x() const;
    int get_y() const;

    //metodo getter per verificare se un nodo è un ostacolo o no
    bool get_is_obstacle() const;

    //metodi getter per calcolare il costo totale
    float get_gCost() const;
    float get_hCost() const;
    float get_fCost() const;

    //metodi setter
    void set_gCost(float gCost);
    void set_is_obstacle(bool isObstacle);

    //metodo getter che restituisce il nodo genitore di un nodo dato
    Node* get_parent() const;

    void set_parent(Node* parent);

    //metodo che calcola la distanza dal nodo finale
    void calculateL_distance(const Node& endNode);

    //metodo che calcola il costo totale
    void calculateFCost();

    bool operator<(const Node& other) const;
    bool operator==(const Node& other) const;

private:
    int x;
    int y;
    float gCost;
    float hCost;
    float fCost;
    Node* parent;
    bool isObstacle;
};

#endif // NODE_H

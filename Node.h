#ifndef NODE_H
#define NODE_H

#include <cmath>
#include <stdexcept>

class Node {
public:
    Node(int x, int y, bool isObstacle=false);
    int get_x1() const;
    int get_y1() const;
    bool get_is_obstacle() const;
    float get_gCost() const;
    float get_hCost() const;
    float get_fCost() const;
    void set_gCost(float gCost);
    void set_is_obstacle(bool isObstacle);
    Node* get_parent() const;
    void set_parent(Node* parent);
    void calculateL_distance(const Node& endNode);
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

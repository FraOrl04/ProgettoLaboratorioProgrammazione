//
// Created by fra on 13/08/24.
//

#ifndef NODE_H
#define NODE_H
class Node {
public:
    int x, y;
    float gCost, hCost, fCost;
    Node* parent;

    Node(int x, int y);

    void calculateHeuristic(const Node& endNode);

    void calculateFCost();

    bool operator==(const Node& other) const ;

    bool operator<(const Node& other) const ;
};

#endif //NODE_H

//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/Grid.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/AStar.h"

TEST(AStarTest, FindPath) {
    Grid grid(10, 10, {{1, 1}, {2, 2}, {3, 3}});
    Node& startNode = grid.nodes[0][0];
    Node& endNode = grid.nodes[9][9];

    std::vector<Node*> path = AStar::findPath(grid, startNode, endNode);
    EXPECT_FALSE(path.empty());
    EXPECT_EQ(path.front(), &startNode);
    EXPECT_EQ(path.back(), &endNode);
}

TEST(AStarTest, PathAvoidsObstacles) {
    Grid grid(10, 10, {{1, 0}, {1, 1}, {1, 2}});
    Node& startNode = grid.nodes[0][0];
    Node& endNode = grid.nodes[0][3];

    std::vector<Node*> path = AStar::findPath(grid, startNode, endNode);
    for (Node* node : path) {
        EXPECT_FALSE(node->isObstacle);
    }
}

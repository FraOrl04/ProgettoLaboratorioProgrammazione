//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/Grid.h"

TEST(GridTest, GridInitialization) {
    std::vector<std::pair<int, int>> obstacles = {{1, 1}, {2, 2}};
    Grid grid(10, 10, obstacles);

    EXPECT_EQ(grid.nodes[1][1].isObstacle, true);
    EXPECT_EQ(grid.nodes[2][2].isObstacle, true);
    EXPECT_EQ(grid.nodes[0][0].isObstacle, false);
}

TEST(GridTest, NodeAccess) {
    Grid grid(10, 10, {});
    Node& node = grid.nodes[5][5];
    EXPECT_EQ(node.x, 5);
    EXPECT_EQ(node.y, 5);
}

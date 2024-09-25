//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProg/Grid.h"

TEST(GridTest, GridInitialization) {
    std::vector<std::pair<int, int>> obstacles = {{1, 1}, {2, 2}};
    Grid grid(10, 10, obstacles);

    EXPECT_EQ(grid.Access_Node()[1][1].get_is_obstacle(), true);
    EXPECT_EQ(grid.Access_Node()[2][2].get_is_obstacle(), true);
    EXPECT_EQ(grid.Access_Node()[0][0].get_is_obstacle(), false);
}

TEST(GridTest, NodeAccess) {
    Grid grid(10, 10, {});
    Node& node = grid.Access_Node()[5][5];
    EXPECT_EQ(node.get_x(), 5);
    EXPECT_EQ(node.get_y(), 5);
}

TEST(GridTest, NegativeDimensions) {
    // Test per verificare che venga sollevata un'eccezione con dimensioni negative
    EXPECT_THROW(Grid g(-10, 10, {}), std::invalid_argument);
}


TEST(GridTest, NegativeObstacles) {
    // Test per verificare che venga lanciata un'eccezione con ostacoli con coordinate negative
    std::vector<std::pair<int, int>> obstacles = {{-1, 5}};

    // Verifica che venga sollevata un'eccezione std::invalid_argument
    EXPECT_THROW(Grid g(10, 10, obstacles), std::invalid_argument);
}

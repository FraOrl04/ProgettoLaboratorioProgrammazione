//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/Grid.h"

TEST(GridTest, GridInitialization) {
    std::vector<std::pair<int, int>> obstacles = {{1, 1}, {2, 2}};
    Grid grid(10, 10, obstacles);

    EXPECT_EQ(grid.nodes1()[1][1].get_is_obstacle(), true);
    EXPECT_EQ(grid.nodes1()[2][2].get_is_obstacle(), true);
    EXPECT_EQ(grid.nodes1()[0][0].get_is_obstacle(), false);
}

TEST(GridTest, NodeAccess) {
    Grid grid(10, 10, {});
    Node& node = grid.nodes1()[5][5];
    EXPECT_EQ(node.get_x1(), 5);
    EXPECT_EQ(node.get_y1(), 5);
}

TEST(GridTest, NegativeDimensions) {
    // Test per verificare che l'eccezione venga sollevata e che il messaggio di errore venga stampato a schermo
    EXPECT_THROW({
        try {
            Grid g(-10, 10, {});
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Le dimensioni della griglia devono essere maggiori di zero.", e.what());
            std::cerr << e.what() << std::endl;  // Stampa il messaggio a schermo
            throw;
        }
    }, std::invalid_argument);
}

TEST(GridTest, NegativeObstacles) {
    // Test per verificare che l'eccezione venga sollevata e che il messaggio di errore venga stampato a schermo
    std::vector<std::pair<int, int>> obstacles = {{-1, 5}};
    EXPECT_THROW({
        try {
            Grid g(10, 10, obstacles);
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Le coordinate degli ostacoli non possono essere negative.", e.what());
            std::cerr << e.what() << std::endl;  // Stampa il messaggio a schermo
            throw;
        }
    }, std::invalid_argument);
}
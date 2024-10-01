//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "../Node.h"

TEST(NodeTest, NodeInitialization) {
    Node node(1,1);
    EXPECT_EQ(node.get_x(), 1);
    EXPECT_EQ(node.get_y(), 1);
    EXPECT_FALSE(node.get_is_obstacle());
}

TEST(NodeTest, SetObstacle) {
    Node node(0, 0);
    node.set_is_obstacle(true);
    EXPECT_TRUE(node.get_is_obstacle());
}

TEST(NodeTest, SetParent) {
    Node node(0, 0);
    Node parent(1, 1);
    node.set_parent(&parent);
    EXPECT_EQ(node.get_parent(), &parent);
}



// Test per verificare che venga sollevata un'eccezione quando le coordinate sono negative
TEST(NodeTest, NegativeCoordinates) {
    // Verifica che il costruttore sollevi std::invalid_argument quando le coordinate sono negative
    EXPECT_THROW({
        Node n(-1, 0, false);  // Caso con coordinate negative
    }, std::invalid_argument);
}
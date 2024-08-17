//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/Node.h"

TEST(NodeTest, NodeInitialization) {
    Node node(1, 1);
    EXPECT_EQ(node.x, 1);
    EXPECT_EQ(node.y, 1);
    EXPECT_FALSE(node.isObstacle);
}

TEST(NodeTest, SetObstacle) {
    Node node(0, 0);
    node.isObstacle = true;
    EXPECT_TRUE(node.isObstacle);
}

TEST(NodeTest, SetParent) {
    Node node(0, 0);
    Node parent(1, 1);
    node.parent = &parent;
    EXPECT_EQ(node.parent, &parent);
}


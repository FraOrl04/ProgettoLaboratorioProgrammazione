//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/Node.h"

TEST(NodeTest, NodeInitialization) {
    Node node(1,1);
    EXPECT_EQ(node.get_x1(), 1);
    EXPECT_EQ(node.get_y1(), 1);
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



TEST(NodeTest, NegativeCoordinates) {
    // Test per verificare che l'eccezione venga sollevata e che il messaggio di errore venga stampato a schermo
    EXPECT_THROW({
        try {
            Node n(-1, 0, false);
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Le coordinate del nodo non possono essere negative.", e.what());
            std::cerr << e.what() << std::endl;  // Stampa il messaggio a schermo
            throw; // Rilancia l'eccezione per permettere a EXPECT_THROW di catturarla
        }
    }, std::invalid_argument);
}
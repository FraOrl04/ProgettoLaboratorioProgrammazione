//
// Created by fra on 17/08/24.
//
#include "../GameCharacter.h"
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/Grid.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProgrammazione/GameCharacter.h"

TEST(AStarTest, FindPath) {
    Grid grid(10, 10, {{1, 1}, {2, 2}, {3, 3}});
    Node& startNode = grid.nodes1()[0][0];
    Node& endNode = grid.nodes1()[9][9];

    std::vector<Node*> path = GameCharacter::findPath(grid, startNode, endNode);
    EXPECT_FALSE(path.empty());
    EXPECT_EQ(path.front(), &startNode);
    EXPECT_EQ(path.back(), &endNode);
}

TEST(AStarTest, PathAvoidsObstacles) {
    Grid grid(10, 10, {{1, 0}, {1, 1}, {1, 2}});
    Node& startNode = grid.nodes1()[0][0];
    Node& endNode = grid.nodes1()[0][3];

    std::vector<Node*> path = GameCharacter::findPath(grid, startNode, endNode);
    for (Node* node : path) {
        EXPECT_FALSE(node->get_is_obstacle());
    }
}

//test percorso non trovato
TEST(AStarTest, NoPathFoundThrowsException) {
    //creiamo una griglia 10*10 con un muro di ostacoli in tutta la mappa
    std::vector<std::pair<int,int>> obstacle;
    for(int x = 0; x<10; x++) {
        obstacle.emplace_back(x, 5);//crea un muro verticale lungo la colonna 5
    }
    Grid grid(10,10,obstacle);
    Node& startNode = grid.nodes1()[0][0];
    Node& endNode = grid.nodes1()[9][9];
    //verifica che l'eccezione venga lanciata quando non c'è un percorso possibile
    try {
        GameCharacter::findPath(grid,startNode,endNode);
        FAIL() <<"Expected std::runtime_error";
    }catch (const std::runtime_error& err) {
        EXPECT_EQ(std::string(err.what()),"percorso non trovato: nessun perscorso esistente per il nodo destinazione");
    }catch (...) {
        FAIL()<<"Expected std::runtime_error";
    }

}
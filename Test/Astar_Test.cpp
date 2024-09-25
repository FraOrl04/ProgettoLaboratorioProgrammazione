//
// Created by fra on 17/08/24.
//
#include "../GameCharacter.h"
#include "gtest/gtest.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProg/Grid.h"
#include "/home/fra/CLionProjects/ProgettoLaboratorioProg/GameCharacter.h"


//test per la ricerca del percorso
TEST(AStarTest, FindPath) {
    Grid grid(10, 10, {{1, 1}, {2, 2}, {3, 3}});
    Node& startNode = grid.Access_Node()[0][0];
    Node& endNode = grid.Access_Node()[9][9];

    std::vector<Node*> path = GameCharacter::findPath(grid, startNode, endNode);
    EXPECT_FALSE(path.empty());
    EXPECT_EQ(path.front(), &startNode);
    EXPECT_EQ(path.back(), &endNode);
}

//test per verificare che gli ostacoli non vengano considerati nel calcolo del percorso
TEST(AStarTest, PathAvoidsObstacles) {
    Grid grid(10, 10, {{1, 0}, {1, 1}, {1, 2}});
    Node& startNode = grid.Access_Node()[0][0];
    Node& endNode = grid.Access_Node()[0][3];

    std::vector<Node*> path = GameCharacter::findPath(grid, startNode, endNode);
    for (Node* node : path) {
        EXPECT_FALSE(node->get_is_obstacle());
    }
}

//test per cacolare che il percorso non venga trovato nel caso
//di un muro che attrversa e blocca la mappa
TEST(AStarTest, NoPathFoundThrowsException) {
    // Creiamo una griglia 10x10 con un muro di ostacoli in tutta la mappa
    std::vector<std::pair<int, int>> obstacle;
    for (int x = 0; x < 10; x++) {
        obstacle.emplace_back(x, 5); // Crea un muro verticale lungo la colonna 5
    }
    Grid grid(10, 10, obstacle);
    Node& startNode = grid.Access_Node()[0][0];
    Node& endNode = grid.Access_Node()[9][9];

    // Verifica che l'eccezione venga lanciata quando non c'è un percorso possibile
    EXPECT_THROW(
        GameCharacter::findPath(grid, startNode, endNode),
        std::runtime_error // o l'eccezione specifica, come PathNotFoundException
    );
}

//test per verificare che tutti i nodi appartengano al percorso
TEST(AStarTest, allNodeintothePath) {
    Grid grid(5,5,{{1,1},{2,1},{3,1},{1,2},{2,2},{2,3},{3,1},{3,2},{3,3}});

    Node& startNode = grid.Access_Node()[0][0];
    Node& endNode = grid.Access_Node()[0][4];

    std::vector<Node*>path= GameCharacter::findPath(grid,startNode,endNode);

    ASSERT_FALSE(path.empty());
    // Verifica che il primo nodo nel percorso sia quello di partenza
    EXPECT_EQ(path.front(), &startNode);

    // Verifica che l'ultimo nodo nel percorso sia quello di arrivo
    EXPECT_EQ(path.back(), &endNode);

    // Verifica che tutti i nodi nel percorso appartengano alla griglia (sono validi)
    for (Node* node : path) {
        EXPECT_TRUE(grid.isNodeInPath(node,path));
    }

}


//test per verificare che il percorso trovato sia il migliore
TEST(AstarTest, minmumPath) {
    Grid grid(5,5,{{1,1},{2,1},{3,1},{1,2},{2,2},{2,3},{3,1},{3,2},{3,3}});

    Node& startNode = grid.Access_Node()[0][0];
    Node& endNode = grid.Access_Node()[0][4];

    std::vector<Node*>path= GameCharacter::findPath(grid,startNode,endNode);

    ASSERT_FALSE(path.empty());

    // Calcolo del costo atteso (percorso più breve manualmente determinato)
    int expectedCost = 4; // In una griglia 5x5 senza ostacoli diretti, il percorso (0,0) -> (0,4) è di 4 passi

    // Calcola il costo del percorso trovato
    int actualCost = path.size()-1; // Il costo è la lunghezza del percorso meno 1 (ogni passo tra i nodi adiacenti ha costo 1)

    // Verifica che il costo del percorso trovato sia il minimo
    EXPECT_EQ(actualCost, expectedCost);

}
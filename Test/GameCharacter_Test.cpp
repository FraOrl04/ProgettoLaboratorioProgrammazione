//
// Created by fra on 17/08/24.
//
#include "gtest/gtest.h"
#include "../GameCharacter.h"
#include  "../Node.h"

TEST(GameCharacterTest, Initialization) {
    Node start(0,0);
    GameCharacter character(&start);

    EXPECT_EQ(character.getCurrentNode(), &start);
    EXPECT_TRUE(character.getPath().empty());
}

TEST(GameCharacterTest, SetPath) {
    Node start(0,0);
    Node next(1,1);
    GameCharacter character(&start);

    std::vector<Node*> path = {&start, &next};
    character.setPath(path);

    EXPECT_EQ(character.getPath().size(), 2);
    EXPECT_EQ(character.getPath().back(), &next);
}

TEST(GameCharacterTest, MoveAlongPath) {
    Node start(0, 0);
    Node next(1, 1);
    GameCharacter character(&start);

    std::vector<Node*> path = {&start, &next};
    character.setPath(path);

    character.move();
    EXPECT_EQ(character.getCurrentNode(), &next);
    EXPECT_TRUE(character.hasReachedDestination());
}

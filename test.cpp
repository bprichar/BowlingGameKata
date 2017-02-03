#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"
#include "game.h"

void rollMany(Game *g, int n, int pins) {
    for (int i = 0; i < n; i++) {
        g->roll(pins);
    }
}

void rollSpare(Game *g) {
    g->roll(5);
    g->roll(5);
}

void rollStrike(Game *g) {
    g->roll(10);
}

TEST_CASE("Test the Bolwing Game", "[game]") {

    Game *g = new Game();

    SECTION("Test Gutter Game") {
        rollMany(g, 20, 0);
        REQUIRE(g->score() == 0);
    }

    SECTION("Test All Ones") {
        rollMany(g, 20, 1);
        REQUIRE(g->score() == 20);
    }

    SECTION("Test One Spare") {
        rollSpare(g);
        g->roll(3);
        rollMany(g, 17, 0);
        REQUIRE(g->score() == 16);
    }

    SECTION("Test One Strike") {
        rollStrike(g);
        g->roll(3);
        g->roll(4);
        rollMany(g, 16, 0);
        REQUIRE(g->score() == 24);
    }

    SECTION("Test Perfect Game") {
        rollMany(g, 12, 10);
        REQUIRE(g->score() == 300);
    }

}

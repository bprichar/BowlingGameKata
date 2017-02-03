#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"
#include "game.h"

void rollMany(Game *g, int n, int pins) {
    for (int i = 0; i < n; i++) {
        g->roll(pins);
    }
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

//    SECTION("Test One Spare") {
//        g->roll(5);
//        g->roll(5); // spare
//        g->roll(3);
//        rollMany(g, 17, 0);
//        REQUIRE(g->score() == 16);
//    }

}

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
        int n = 20;
        int pins = 0;
        rollMany(g, n, pins);
        REQUIRE(g->score() == 0);
    }

    SECTION("Test All Ones") {
        for (int i=0; i<20; i++) {
            g->roll(1);
        }
        REQUIRE(g->score() == 20);
    }

}

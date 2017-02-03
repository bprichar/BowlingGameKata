#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"
#include "game.h"

TEST_CASE("Test the Bolwing Game", "[game]") {

    Game *g = new Game();

    SECTION("Test Gutter Game") {
        for (int i=0; i<20; i++) {
            g->roll(0);
        }
        REQUIRE(g->score() == 0);
    }

    SECTION("Test All Ones") {
        for (int i=0; i<20; i++) {
            g->roll(1);
        }
        REQUIRE(g->score() == 20);
    }

}

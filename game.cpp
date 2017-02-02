#include "game.h"

void Game::roll(int pins) {
    myscore += pins;
}

int Game::score() {
    return myscore;
}

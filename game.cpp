#include "game.h"

void Game::roll(int pins) {
    my_score += pins;
    rolls[current_roll++] = pins;
}

int Game::score() {
    return my_score;
}

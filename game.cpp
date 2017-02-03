#include "game.h"

Game::Game() {
    current_roll = 0;
    my_score = 0;
    rolls.resize(21);
}

void Game::roll(int pins) {
    my_score += pins;
    rolls[current_roll++] = pins;
}

int Game::score() {
    int my_score = 0;
    for (std::size_t i = 0; i < rolls.size(); i++) {
        my_score += rolls[i];
    }
    return my_score;
}

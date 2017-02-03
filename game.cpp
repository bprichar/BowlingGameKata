#include "game.h"

Game::Game() {
    current_roll = 0;
    rolls.resize(21);
}

void Game::roll(int pins) {
    rolls[current_roll++] = pins;
}

int Game::score() {
    int my_score = 0;
    for (std::size_t i = 0; i < rolls.size(); i++) {
        if (rolls[i] + rolls[i+1] == 10) { // spare
            my_score += rolls[i+2];
        }
        my_score += rolls[i];
    }
    return my_score;
}

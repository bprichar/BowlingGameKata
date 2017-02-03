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
    int i = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (rolls[i] + rolls[i+1] == 10) {
            my_score += 10 + rolls[i+2];
            i += 2;
        } else {
            my_score += rolls[i] + rolls[i+1];
            i += 2;
        }
    }
    return my_score;
}

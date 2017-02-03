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
    int frame_index = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (isSpare(frame_index)) {
            my_score += 10 + rolls[frame_index+2];
            frame_index += 2;
        } else {
            my_score += rolls[frame_index] + rolls[frame_index+1];
            frame_index += 2;
        }
    }
    return my_score;
}

bool Game::isSpare(int frame_index) {
    return rolls[frame_index] + rolls[frame_index+1] == 10;
}

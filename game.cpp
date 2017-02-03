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
        if (rolls[frame_index] == 10) {// strike
            my_score += 10 + strikeBonus(frame_index);
            frame_index++;
        } else if (isSpare(frame_index)) {
            my_score += 10 + spareBonus(frame_index);
            frame_index += 2;
        } else {
            my_score += sumOfBallsInFrame(frame_index);
            frame_index += 2;
        }
    }
    return my_score;
}

int Game::sumOfBallsInFrame(int frame_index) {
    return rolls[frame_index] + rolls[frame_index+1];
}

int Game::spareBonus(int frame_index) {
    return rolls[frame_index + 2];
}

int Game::strikeBonus(int frame_index) {
    return rolls[frame_index+1] + rolls[frame_index+2];
}

bool Game::isSpare(int frame_index) {
    return rolls[frame_index] + rolls[frame_index+1] == 10;
}

#ifndef THE_GAME
#define THE_GAME 1

#include <vector>

class Game {
  public:
    Game();
    void roll(int pins);
    int score();

  private:
    std::vector<int> rolls;
    int current_roll;
    bool isSpare(int frame_index);
    int sumOfBallsInFrame(int frame_index);
    int spareBonus(int frame_index);
};
#endif

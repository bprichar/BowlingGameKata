#ifndef THE_GAME
#define THE_GAME 1

#include <vector>

class Game {
  public:
    Game();
    void roll(int pins);
    int score();
    bool isSpare(int frame_index);

  private:
    std::vector<int> rolls;
    int current_roll;
};
#endif

#ifndef THE_GAME
#define THE_GAME 1
class Game {
  public:
    void roll(int pins);
    int score();

  private:
    int my_score;
    int rolls[21];
    int current_roll;
};
#endif

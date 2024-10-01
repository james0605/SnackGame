#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Food.h"
#include "Position.h"

class Game{
public:
    Game(int width, int height);
    char lastKey;
    void run();
    Position direction;
    void processInput();
    int total_score;

private:
    int width;
    int height;
    bool isRunning;
    Snake snake;
    Food food;

    

    void update();
    void render();
    void generateFood();
    void exit();

};


#endif // GAME_H
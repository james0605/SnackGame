#ifndef FOOD_H
#define FOOD_H

#include "Position.h"
#include <cstdlib>
#include <vector>
class Food {
public:
    Position position;
    int score;

    Food(int x, int y, int score = 10) : position(x, y) ,score(score) {}

    Position getPosition() const{
        return position;
    }

    int getScore() const{
        return score;
    }

    void setPosition(int x, int y){
        position.x = x;
        position.y = y;
    }
};


#endif // FOOD_H
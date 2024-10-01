#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <vector>
#include "Food.h"
#include "Position.h"

class Snake{
public:
    std::deque<Position> body;
    int length;

    Snake(Position start, int start_len);

    void move(const Position& newHead);
    void grow();
    Position getHead() const;
    bool checkSelfCollision() const;

};

#endif //SNAKE_H
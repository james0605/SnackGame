#include <iostream>
#include "../lib/Snake.h"

void checkBody(const std::deque<Position>& body) {
    std::cout << "body part : ";
    for (const Position& bodyPart: body){
        std::cout << "(" << bodyPart.x << ", " << bodyPart.y << "), ";
    }
    std::cout << std::endl;
}


int main() {
    Snake snake(Position(5, 5), 3);

    // test init
    Position head = snake.getHead();
    std::cout << "Initial head position: (" << head.x << ", " << head.y << ")" << std::endl;

    // test move
    snake.move(Position(6, 5));
    head = snake.getHead();
    std::cout << "Head position After move: (" << head.x << ", " << head.y << ")" << std::endl;

    // test grow
    snake.grow();
    
    checkBody(snake.body);

    // test move after grow
    snake.move(Position(7, 5));
    checkBody(snake.body);

    // test checkSelfCollision (Won't happen)
    
    if (snake.checkSelfCollision()){
        std::cout << "Snake collided with itself" << std::endl;
    }
    else{
        std::cout << "No collided detected" << std::endl;
    }
    // test checkSelfCollision (Will happen)
    snake.grow();
    snake.move(Position(6, 5));
    checkBody(snake.body);
    if (snake.checkSelfCollision()){
        std::cout << "Snake collided with itself" << std::endl;
    }
    else{
        std::cout << "No collided detected" << std::endl;
    }
    


    return 0;
}

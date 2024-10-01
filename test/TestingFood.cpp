#include <iostream>
#include "../lib/Food.h"

int main(){
    Food food(1, 2, 5);
    std::cout << "food position " << food.position.x << " " << food.position.y << std::endl;
    std::cout << "score " << food.score << std::endl;
}
#include <iostream>
#include "../lib/Position.h"

int main() {
    Position p1(0, 1);
    Position p2(1, 1);

    if (p1 != p2) {
        std::cout << "true" << std::endl; 
    }

}

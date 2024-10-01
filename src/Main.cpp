#include "../lib/Game.h"

#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned>(time(0)));


    Game game(30, 30);
    game.run();

    return 0;
}

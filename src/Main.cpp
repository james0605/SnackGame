#include "../lib/Game.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int width, height;
    cout << "Input width and height" << endl;
    cin >> width >> height;
    Game game(width, height);
    game.run();

    return 0;
}

#include <iostream>
#include "../lib/Game.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(0))); // 设置随机数种子

    // 创建一个宽度为20，高度为10的游戏实例
    Game game(20, 20);
    game.run(); // 运行游戏

    return 0;
}

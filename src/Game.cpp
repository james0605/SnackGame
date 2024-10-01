#include <iostream>
#include "../lib/Game.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono> 
#include <thread> 
#include <windows.h>

#define VK_LEFT 75
#define VK_UP 72
#define VK_RIGHT 77
#define VK_DOWN 80


// 用來移動光標到指定位置
void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; // 隱藏光標
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


Game::Game(int width, int height): width(width + 2), height(height + 2), snake(Position(5, 5), 3), food(1, 1), direction(Position(0, 1)), total_score(0){
    isRunning = true;
    lastKey = 0;
    generateFood();
}

void Game::run(){
    while (isRunning){
        processInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}
void Game::exit(){
    isRunning = false;
    std::cout << "Exiting game" << std::endl;
    std::cout << "Press any key to exit..." << std::endl;
    _getch();
}

void Game::processInput(){
    if (_kbhit()){
        char key = _getch();
        if (key == -32){
            key = _getch();
            if (key != lastKey){
                lastKey = key;   
                switch (key){
                    case VK_UP: // up
                        std::cout << "Up arrow pressed" << std::endl;
                        direction = Position(0, -1);
                        break;
                    case VK_DOWN: // down
                        std::cout << "Down arrow pressed" << std::endl;
                        direction = Position(0, 1);
                        break;
                    case VK_LEFT: // left
                        std::cout << "Left arrow pressed" << std::endl;
                        direction = Position(-1, 0);
                        break;
                    case VK_RIGHT: // right
                        std::cout << "Right arrow pressed" << std::endl;
                        direction = Position(1, 0);
                        break;
                    default:
                        break; 
                } 
            }
            
        }
    }
}

void Game::update(){
    // update snake position
    Position newHead = snake.getHead();
    newHead.x += direction.x;
    newHead.y += direction.y;
    snake.move(newHead);

    // check collision
    if (snake.checkSelfCollision()){
        // game over
        std::cout << "Self Collision!!!" << std::endl;
        exit();
    }

    if (newHead.x < 1 || newHead.x >= height - 1){
        // game over
        std::cout << "Collision!!!" << std::endl;
        exit();
    }
    if (newHead.y <  1 || newHead.y >= width - 1){
        // game over
        std::cout << "Collision!!!" << std::endl;
        exit();
    }

    // check if eat Food
    if (newHead == food.getPosition()){
        snake.grow();
        total_score += food.score;
        generateFood();
    }
}

void Game::render(){

    // clear terminal
    hideCursor();
    setCursorPosition(0, 0); // 將光標移到頂部左邊

    // board
    std::vector<std::vector<char>> board(height, std::vector<char>(width, ' '));

    // row boundary
    for(int i = 0; i < width; i++)
        board[0][i] = board[height - 1][i] = '-';

    // column boundary
    for (int i = 0; i < height; i++)
        board[i][width - 1] = board[i][0] = '|';

    // snake
    for (const Position& bodyPart : snake.body) {
        if (bodyPart.x >= 0 && bodyPart.x < width && bodyPart.y >= 0 && bodyPart.y < height) {
            board[bodyPart.y][bodyPart.x] = 'O'; 
        }
    }

    // food
    Position foodPosition = food.getPosition();
    if (foodPosition.x >= 0 && foodPosition.x < width && foodPosition.y >= 0 && foodPosition.y < height) {
        board[foodPosition.y][foodPosition.x] = 'X'; 
    }

    // print
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }

    std::cout << "Score: " << total_score << std::endl;
}


void Game::generateFood() {
    Position newFoodPosition;
    do {
        newFoodPosition.x = rand() % width;
        newFoodPosition.y = rand() % height;
    } while (std::find(snake.body.begin(), snake.body.end(), newFoodPosition) != snake.body.end());

    food.setPosition(newFoodPosition.x, newFoodPosition.y);
}
#include "../lib/Snake.h"

Snake::Snake(Position start, int start_len = 3) {
    for (int i = 0; i < start_len; i++)
        body.push_back(start);
}

void Snake::move(const Position& newHead) {
    body.push_back(newHead);
    body.pop_front();
}

void Snake::grow() {
    body.push_front(body.front());
}

Position Snake::getHead() const {
    return body.back();
}

bool Snake::checkSelfCollision() const {
    Position head = getHead();
    for (size_t i = 0; i < body.size() - 1; ++i) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

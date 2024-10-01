#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x, y;

    Position(int x = -1, int y = -1) : x(x), y(y) {}

    bool operator==(const Position& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Position& other) const {
        return !(x == other.x && y == other.y);
    }
};

#endif // POSITION_H

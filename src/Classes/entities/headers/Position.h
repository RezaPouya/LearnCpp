#pragma once

struct Position {
private:
    int x, y, z;

public:
    Position(int x = 0, int y = 0, int z = 0);
    void Move(int xAdd, int yAdd, int zAdd, int moveSpeed);

    // Const getters
    int GetX() const;
    int GetY() const;
    int GetZ() const;
};
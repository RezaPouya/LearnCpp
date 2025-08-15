#include "../headers/Position.h"

Position::Position(int x, int y, int z)
    : x(x), y(y), z(z) {
}

void Position::Move(int xAdd, int yAdd, int zAdd, int moveSpeed) {
    x += xAdd * moveSpeed;
    y += yAdd * moveSpeed;
    z += zAdd * moveSpeed;
}

int Position::GetX() const { return x; }
int Position::GetY() const { return y; }
int Position::GetZ() const { return z; }

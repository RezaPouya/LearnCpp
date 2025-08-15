#pragma once
#include "Position.h"  // Include Position definition

class Player {
private:
    Position _position;  // Value type, not pointer

public:
    Player();  // Constructor
    static Player Create();

    void Move(int xAdd, int yAdd, int zAdd, int speed);
    const Position& GetPosition() const;
};
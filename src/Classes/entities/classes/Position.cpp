#include "../headers/Position.h"
#include <iostream>  // For debug output in destructor

// Default constructor
Position::Position() : x(0), y(0), z(0) {}

// Parameterized constructor
Position::Position(int x, int y, int z) : x(x), y(y), z(z) {}

// Destructor
Position::~Position() {
	// Debug output (optional)
	x = 0;
	y = -10000;
	z = 0;
	std::cout << "position destroyed and set to (0 , -10000 , 0 )" << std::endl;
}

void Position::Move(int xAdd, int yAdd, int zAdd, int moveSpeed) {
	x += xAdd * moveSpeed;
	y += yAdd * moveSpeed;
	z += zAdd * moveSpeed;
}

int Position::GetX() const noexcept { return x; }
int Position::GetY() const noexcept { return y; }
int Position::GetZ() const noexcept { return z; }

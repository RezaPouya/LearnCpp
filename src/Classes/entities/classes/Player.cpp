#include "../headers/Player.h"
#include <utility>  // For std::move

Player::Player(int x, int y, int z)
	: _position(std::make_unique<Position>(x, y, z)) {
}

Player::Player(Player&& other) noexcept
	: _position(std::move(other._position)) {
}

Player& Player::operator=(Player&& other) noexcept {
	if (this != &other) {
		_position = std::move(other._position);
	}
	return *this;
}

Player Player::Create() {
	return Player();
}

void Player::Move(int xAdd, int yAdd, int zAdd, int speed) {
	_position->Move(xAdd, yAdd, zAdd, speed);
}

const Position& Player::GetPosition() const {
	return *_position;
}
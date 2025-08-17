#include "../headers/Player.h"
#include <utility>  // For std::move

// member initializer is faster 
Player::Player(int x, int y, int z)
	: m_position(std::make_unique<Position>(x, y, z)) {
}

Player::Player(Player&& other) noexcept
	: m_position(std::move(other.m_position)) {
}

Player& Player::operator=(Player&& other) noexcept {
	if (this != &other) {
		m_position = std::move(other.m_position);
	}
	return *this;
}

Player Player::Create() {
	return Player();
}

void Player::Move(int xAdd, int yAdd, int zAdd, int speed) {
	m_position->Move(xAdd, yAdd, zAdd, speed);
}

const Position& Player::GetPosition() const {
	return *m_position;
}
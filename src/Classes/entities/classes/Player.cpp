#include "../headers/Player.h"

Player::Player() : _position() {}

Player Player::Create() {
    return Player();
}

void Player::Move(int xAdd, int yAdd, int zAdd, int speed) {
    _position.Move(xAdd, yAdd, zAdd, speed);
}

const Position& Player::GetPosition() const {
    return _position;
}

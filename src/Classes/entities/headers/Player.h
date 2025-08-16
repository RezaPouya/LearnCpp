#pragma once
#include "Position.h"
#include <memory>

class Player {
private:
    std::unique_ptr<Position> m_position;

public:
    explicit Player(int x = 0, int y = 0, int z = 0);
    ~Player() = default;

    // Delete copy operations (unique_ptr is non-copyable)
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    // Move operations
    Player(Player&& other) noexcept;
    Player& operator=(Player&& other) noexcept;

    static Player Create();
    void Move(int xAdd, int yAdd, int zAdd, int speed);
    const Position& GetPosition() const;
};
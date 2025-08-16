#pragma once

struct Position {
private:
    int x;
    int y;
    int z;

public:
    // Default constructor (initializes to 0,0,0)
    Position();

    // Parameterized constructor
    explicit Position(int x, int y, int z);

    // Destructor
    ~Position();

    // Movement method
    void Move(int xAdd, int yAdd, int zAdd, int moveSpeed);

    // Const getters -- read-only , thread safe 
    // const doesn’t automatically mean thread-safe (e.g., if members are pointers).
    int GetX() const noexcept;
    int GetY() const noexcept;
    int GetZ() const noexcept;
};
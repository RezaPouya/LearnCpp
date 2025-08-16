#include <iostream>
#include "entities/headers/Player.h"
#include "entities/headers/Position.h"
#include "entities/headers/Logger.h"

#define Log(x) std::cout << x << std::endl ; 

// when we moving out from this context , DeConstructor of position class is called 
// if we use new(), we should call deConstructor
void Function() {
    Position pos(10, 15, 18);
    pos.~Position();
}

int main()
{

    std::cout << "Only difference between class and struct." << std::endl <<
        " struct member by default are public, while class members are private !" 
        << std::endl << std::endl << 
        " The only reason struct exists in cpp is because cpp wants to have backward compeability with c , c has struct" 
        << std::endl << std::endl <<
        " use struct for set of variable like vector2 and vector3, which doens't have massive functionality in it" 
        << std::endl << std::endl <<
        " use struct for set of variable like vector2 and vector3, which doens't have massive functionality in it"
        << std::endl << std::endl
        ;

    Player player;

    PouyaLogger::Logger logger(PouyaLogger::Warn);

    //logger.SetLogLevel(PouyaLogger::Information);
    
    logger.Info("Player is created");

    // Correct logging:
    // If using a {}-style formatter:
    //Log("Player current position: {}", player.GetPosition().GetX());

    std::cout << "Player current position: (0,0,0) " << std::endl;

    std::cout << "Move Player in direction of  (1,1,1) with speed of 1. ";

    player.Move(1, 1, 1, 1);

    logger.Info("Player moved by (1,1,1,1)");
    std::cout << "Player current position: " << std::endl <<
        "\t x:" << player.GetPosition().GetX() <<
        "\t y:" << player.GetPosition().GetY() <<
        "\t z:" << player.GetPosition().GetZ() <<
        std::endl;

    std::cout << "Move Player in direction of  (3,3,4) with speed of 2. ";
    
    player.Move(3, 3, 4, 2);
    logger.Info("Player moved by (3,3,4,2)");
    std::cout << "Player current position: " << std::endl <<
        "\t x:" << player.GetPosition().GetX() <<
        "\t y:" << player.GetPosition().GetY() <<
        "\t z:" << player.GetPosition().GetZ() <<
        std::endl;

    logger.Warning("Player moved by (3,3,4,2)");
    logger.Error("Player moved by (3,3,4,2)");

    Function();

    std::cout << "calling another position object " << std::endl;
    Position pos(10, 15, 18);
    pos.~Position();

    std::cin.get();

    return 0;
}

// its 
struct Vector2 {
    float X;
    float Y;

    void Add(const Vector2& other) {
        this->X += other.X;
        this->Y += other.Y;
    }
};
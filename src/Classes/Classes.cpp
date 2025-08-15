#include <iostream>
#include "entities/headers/Player.h"
#include "entities/headers/Position.h"

#define Log(x) std::cout << x << std::endl ; 


int main()
{
    Player player;

    // Correct logging:
    // If using a {}-style formatter:
    //Log("Player current position: {}", player.GetPosition().GetX());

    std::cout << "Player current position: (0,0,0) " << std::endl;

    std::cout << "Move Player in direction of  (1,1,1) with speed of 1. ";

    player.Move(1, 1, 1, 1);

    std::cout << "Player current position: " << std::endl <<
        "\t x:" << player.GetPosition().GetX() <<
        "\t y:" << player.GetPosition().GetY() <<
        "\t z:" << player.GetPosition().GetZ() <<
        std::endl;



    std::cout << "Move Player in direction of  (3,3,4) with speed of 2. ";
    
    player.Move(3, 3, 4, 2);
    
    std::cout << "Player current position: " << std::endl <<
        "\t x:" << player.GetPosition().GetX() <<
        "\t y:" << player.GetPosition().GetY() <<
        "\t z:" << player.GetPosition().GetZ() <<
        std::endl;

    std::cin.get();

    return 0;
}



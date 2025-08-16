#include <iostream>


class Entity {
public:
	float X;
	float Y;
	explicit Entity(float x, float y) : X(x), Y(y) {}

	void Move(float x, float y, float speed) {
		X = x * speed;
		Y = y * speed;
	}
};

class Player : public Entity {

public:
	const char* Name;
	Player(const char* name, float x, float y)  : Entity(x, y) , Name(name) {}
};

void PrintEntityPos(const Entity& entity) {
	std::cout << "Entity is at (" << entity.X << "," << entity.Y << ")." << std::endl;
}

int main()
{
	Entity entity(2.1f, 3.5f);

	Player player("Reza", 0.1f, 0.5f);

	std::cout << "size of entity obj is '" << sizeof(entity) << std::endl;
	std::cout << "size of player obj is '" << sizeof(player) << std::endl;

	std::cout << "Player name is '" << player.Name <<
		"' and hen is at (" << player.X << "," << player.Y << ")." 
		<< std::endl;

	PrintEntityPos(player);

	std::cin.get();
}


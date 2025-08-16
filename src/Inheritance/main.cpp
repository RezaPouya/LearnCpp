#include <iostream>


class Entity {
public:
	float X;
	float Y;
	explicit Entity(float x, float y) : X(x), Y(y) {}

	virtual std::string GetName() const { return "Entity"; }
	virtual std::string GetName2() const { return "Entity2"; }

	void Move(float x, float y, float speed) {
		X = x * speed;
		Y = y * speed;
	}

	void PrintPosition() const {
		std::cout << "Entity is at (" << X << "," << Y << ")." << std::endl;
	}
};

class Player : public Entity {

public:
	const std::string Name;
	Player(const std::string& name, float x, float y) : Entity(x, y), Name(name) {}

	 std::string GetName() const override { return this->Name; }
	 std::string GetName2() const final { return this->Name + " 2 " ; }

	// hid base class method
	void PrintPosition() const {
		std::cout << "Player '" << Name << "' is at (" << X << "," << Y << ")." << std::endl;
	}
};

void PrintEntityPos(const Entity& entity) {
	std::cout << "Entity is at (" << entity.X << "," << entity.Y << ")." << std::endl;
}


void PrintName (const Entity* entity) {
	std::cout << entity->GetName() << std::endl; // !!!!!! we excepted player name 'Reza'
}


// virutal functions : virtual functions are called 'dynamic dispatch' which compilers typically implement via V-Table
// V-Table is a table which contains mapping for all the virtual functions inside on our base class , so we can mapped
// them to correct function on run-time.

// they are not free 
//		1- they need extra memory for keeping v-Table ( a member pointer inside base class to point to v-table and v-table) 
//		2- when we call virtual function , we should check v-table which has performance cost
// those cost are for very weak embeded systems !!! 


int main()
{
	Entity entity(2.1f, 3.5f);
	entity.GetName();
	std::cout << entity.GetName() << std::endl;
	entity.PrintPosition();

	std::cout << std::endl;
	std::cout << std::endl;

	Player player("Reza", 0.1f, 0.5f);
	std::cout << player.GetName() << std::endl;
	player.PrintPosition();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "size of entity obj is '" << sizeof(entity) << std::endl;
	std::cout << "size of player obj is '" << sizeof(player) << std::endl;

	std::cout << "Player name is '" << player.Name <<
		"' and hen is at (" << player.X << "," << player.Y << ")."
		<< std::endl;

	PrintEntityPos(player);


	Entity* en = &player;
	PrintName(en);

	std::cout << en->GetName2() << std::endl; // !!!!!! we excepted player name 'Reza'

	std::cin.get();
}


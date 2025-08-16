#include <iostream>


class Entity {
public:
	float X;
	float Y;
	explicit Entity(float x, float y) : X(x), Y(y) {}

	virtual std::string GetName() const { return "Entity"; }

	void Move(float x, float y, float speed) {
		X = x * speed;
		Y = y * speed;
	}
};

class Player : public Entity {

public:
	const std::string Name;
	Player(const std::string& name, float x, float y) : Entity(x, y), Name(name) {}

	std::string GetName() const override { return this->Name; }
};

// pure virtual function allowed us to defined a function without body in base class which should be implemented in 
// derived classes 
int main()
{
	std::cin.get();
}



#include <iostream>


class IPrintable {
public:
	virtual ~IPrintable() = default;               // Good practice: virtual destructor
	virtual std::string GetClassName() const = 0;  // Pure virtual function , when use ( = 0 ) , it should be overrided in sub-class
};


class Entity : public IPrintable {

public:
	
	float X;
	float Y;
	
	explicit Entity(float x, float y) : X(x), Y(y) {}

	virtual std::string GetName() const { return "Entity"; }

	void Move(float x, float y, float speed) {
		X = x * speed;
		Y = y * speed;
	}

	std::string GetClassName() const override {
		return "Entity";
	}
};

/// <summary>
/// Use final (C++11) if a subclass should not be overridden further
/// </summary>
class Player final : public Entity , public IPrintable {

public:
	const std::string Name;

	Player(const std::string& name, float x, float y) : Entity(x, y), Name(name) {}

	std::string GetName() const override { return this->Name; }

	std::string GetClassName() const override {
		return "Player";
	}
};

// pure virtual function allowed us to defined a function without body in base class which should be implemented in 
// derived classes 
int main()
{
	Entity entity(12.4f, 5.4f);
	std::cout << entity.GetClassName() << std::endl;  // Output: "Entity"

	Player player("Reza" , 12.4f, 5.4f);
	std::cout << player.GetClassName() << std::endl;  // Output: "Entity"
	std::cin.get();
}



#include <iostream>
#include <format>

class Entity {
public:
	std::string name;
	int x{}, y{};  // Value initialization to 0
	Entity(const std::string& name) : name(name), x(0), y(0) {
		std::cout << std::format("Entity {} is created!\n", this->name);
	};


	~Entity() {
		std::cout << std::format("Entity {} is destroyed!\n", this->name);
	}

};

class ScopedEntityPtr { // we can use std library and unique and smart pointer for this purpose 
private:
	Entity* m_Ptr;

public:
	ScopedEntityPtr(Entity* entity) : m_Ptr(entity) {}
	~ScopedEntityPtr() { delete m_Ptr; }
};

int* CreateArray() {
	int* array = new int[50];
	return array;
}

void FillArray(int* const array, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		array[i] = i + 1;
	}
}

int main()
{
	int arr[50];
	FillArray(arr, 50);

	std::cout << "enter the scope\n\n";
	{
		ScopedEntityPtr scopedPtr = new Entity("scopedEntity");
		std::cout << "Start of Scope\n\n";
		Entity entity("stacked entity");
		Entity* entity2 = new Entity("heap entity");
		std::cout << "End of Scope\n\n";
		int* array = CreateArray();
	}

	std::cout << "Out of scope\n\n";
	std::cin.get();
}

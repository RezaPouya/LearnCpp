#include <iostream>
#include <string>
using String = std::string;

// there are several part of memory that our application use 
// as programmer we work with 2 part :
// - stack ( scope specified ) short lived and at max 1 Megabyte ( depend on compiler ) 
//      -- their lifetime is actually controlled by scope that they were defined into it 
//      -- when stack ends , all memory in that stack frame get poped ( get freed at once ) 
//      -- much more easier to deal and reason with and much more faster 
//      -- but has very limited memory ( at max 1-2 Megabyte ) 
// - heap ( app specified ) long lived and much larger and vague ( we need to manage it ) 
//      -- big big mysterious memory

class Entity {
private:
	String m_Name;

public:
	Entity() : m_Name(String("Unknown")) {};
	explicit Entity(const String& name)  : m_Name(name){}
	const String& GetName() const { return m_Name; }
};
 
void Function() {
	int a = 2;
	Entity entity("Reza Developer");
} // all the member will destroy at here .


int main()
{
	// created on stack 
	// if you can create an object like this , do it.
	// this the faster and most managed way of creating object in cpp 
	Entity entity("Reza Pouya"); 

	std::cout << entity.GetName() << std::endl;

	Function();

	Entity* ePtr; 

	{ // this is just empty scope
		Entity entity2("Reza Pouya");
		ePtr = &entity2;
		std::cout << ePtr << std::endl;
		std::cout << "Get Name from scoped: " << ePtr->GetName() << std::endl;
	}

	std::cout << ePtr << std::endl;
	std::cout << "Get Name outside scoped: " << ePtr->GetName() << std::endl;


	Entity* ePtr2;

	{ // this is just empty scope
		Entity* entity3 = new Entity("Reza Pouya");
		ePtr2 = entity3;
		std::cout << ePtr2 << std::endl;
		std::cout << "Entity Pointer 2 - Get Name from scoped: " << ePtr2->GetName() << std::endl;
		// delete entity3; // calling this will cause error because the entity and ePtr2 will be deleted from memory 
	}

	std::cout << ePtr2 << std::endl;
	std::cout << "Entity Pointer 2 - Get Name outside scoped: " << ePtr2->GetName() << std::endl;
	delete ePtr2;

    std::cin.get();
}


#include <iostream>
#include <string>
using String = std::string;


// THE FACT THAT YOU ARE USING C-PP MEANS YOU SHOULD CARE ABOUT MEMORY USAGES, OPTIMIZATION , SIZE OF APP 

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
	explicit Entity(const String& name) : m_Name(name) {}
	const String& GetName() const { return m_Name; }
};

void Function() {
	int a = 2;
	Entity entity("Reza Developer");
} // all the member will destroy at here .

// NEW KEYWORD:
// use can use new for class , struct , primary data type like int ,
// by using new you say that you want to allocate memory on the heap 
// new base on context , search in Free Address List and find enough memory block and allocate it to your variable/instance 
// when it find the memory , it as os to give that block of memory to it .  
// int* i = new int() ; // find 4 byte of free memory , ask os to give it to variable 'i' which will give 4 byte of memory to us
// now we should search and find the block of memory and return a pointer to block of memory,
// so using new has overhead compare to stack allocated instance 
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

	// because we called new keyword , an memory is created on the heap , so we should manually delete it .
	// ( unless we use smart_pointer ) 
	delete ePtr2;


	int a = 5;
	const int* b = new int(a);
	int* const arr = new int[50]; // 200 bytes 

	for (int i = 0; i < 50; i++) {
		arr[i] = i + 1  ;
	}

	std::cout << "b is defined on heap 'b' " << b << std::endl;
	std::cout << "b is defined on heap '*b' " << *b << std::endl;
	std::cout << "arr is defined on heap ' " << *arr << std::endl;
	std::cout << "arr is defined on heap 'arr[5]' " << arr[5] << std::endl;


	delete b;
	delete arr;

	// new allocate memory in heap and also call default constructor for class 
	const Entity* newEntity = new Entity(); 
	const Entity* arrayOfEntity = new Entity[50];

	// under cover , new calling this function and ask it to give it requested memory 
    // malloc doesn't call object constructor 
	const void* voidPtr =  (Entity*)malloc(sizeof(Entity) * 50); 

	delete newEntity; // calls c function free() , also calls destructors 
	delete[] arrayOfEntity; 
	delete voidPtr;





	std::cin.get();
}


#include <iostream>

// const is a promise , it can be changed if you really want !!!

using String = std::string;

class Entity {
private:
	int m_X;
	mutable int var; // lets this variable be changed in const function ( first meaning of mutable ) 
	int* m_Y;
	int* m_a, m_b; /// here m_b is not a pointer if we write all member in a line 
	// if we want to make m_b a pointer as well we should write '*m_b'

public:
	int GetX() const {
		//m_X = 2; /// is not allowed because we market it as const ,
				   /// which mean it cannot modify variable in its scoped

		var = 2; 
		return m_X;
	}

	/// <summary>
	/// we are returning a pointer that we cannot change it content and reassign it 
	/// and the GetY() promisess that not 
	/// change any varible inside it 
	/// </summary>
	/// <returns></returns>
	const int* const GetY() const {

		return m_Y;
	}

	int* GetA() {

		return m_a;
	}

	int GetX() {
		return m_X;
	}

	void SetX(const int* value) {
		m_X = *value;
	}

	void SetX(const int value) {
		m_X = value;
	}

};

class MutableExample {
private:
	String m_Name;
	mutable int m_DebugCallCount = 0;
public:

	
	// const mean we cannot change actual class member in context of this method 
	const String& GetName() const {
		MutableExample::m_DebugCallCount++;
		return m_Name;
	}
};

void PrintX(const Entity& entity) { // mean we cannot change the 
	std::cout << entity.GetX() << std::endl;
}

void PrintX( Entity& entity) { // we can change the content of entity because its a reference 
	std::cout << entity.GetX() << std::endl;
}

///// <summary>
///// i cannot modify the entity because we pass it as const Entity& 
///// </summary>
//void PrintA(const Entity& entity) { // mean we cannot change the 
//	entity = Entity;
//	std::cout << entity.GetA() << std::endl;
//	// we cannot use GetA becauce its not const and dose not gurantty to not 
//	// change  content of entity 
//}

int main()
{
	int a = 5;
	int* ptr = &a;
	*ptr = 5; // allowed 


	int a2 = 5;
	int b2 = 6;
	const int* ptr2 = &a2;  // we cannot change the content of the pointer but we are allowed to re-assign it 
	ptr2 = &b2; // allowed 
	// *ptr2 = 5; // not allowed 

	int a3 = 5;
	int b3 = 6;
	int* const ptr3 = &a3; // we can change content of the pointer but we are not allowed to re-assign it 
	*ptr3 = 5; // not allowed 
	//*ptr3 = &b6; // not allowed 

	int a4 = 99;
	int b4 = 777;
	const int* const ptr4 = &a4;
	//*ptr4 = 6;; // not allowed 
	// ptr4 = &b4 // not allowed 


	const MutableExample me;
	me.GetName();

	// another use of mutable is within lambda ( little throw away functions ) 

	int x = 8;

	// capture parameters:
	// [xs] --> by value ,
	// [&xs] --> by reference ,
	// [&] --> pass everything by reference ,
	// [=] --> pass everything by value

	auto func = [&x]() {
		//xs++; // its not allwed , unless we capture it in as [&xs]
		x++;
		std::cout << "Hello from lambda expression 1 in cpp - PASS BY REFERENCE  'xs' is: " << xs << std::endl;
		}; // func 


	auto func2 = [x]()  {
		//xs++;// its not allowed 
		std::cout << "Hello from lambda expression 2 in cpp - PASS BY VALUE  'xs' is: " << xs << std::endl;
		}; // func


	auto func3 = [=]() mutable {
		x++;
		std::cout << "Hello from lambda expression 2 in cpp - PASS BY VALUE ( mutable lambda )  'xs' is: " << xs << std::endl;
		};  // its just make an copy of xs and the increase the copy  , outside of this function x still have 


	func();
	func2();
	func3();
	func();
	func2();
	func3();

	std::cin.get();
}

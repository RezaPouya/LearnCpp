#include <iostream>
#include <string>
#include <format>

// copy takes time , so we should know what we are doing!

class MyString {
private:

	char* m_Buffers; 
	unsigned int  m_BufferSize = {};

public:
	explicit MyString(const char* str) {
		
		m_BufferSize = strlen(str);
		
		m_Buffers = new char[m_BufferSize + 1]; // + 1 is for termination character 
		memcpy(m_Buffers, str, strlen(str));
		m_Buffers[m_BufferSize] = 0; // '\0'; // to add termination character to end of string 
	}

	// copy constructor 
	//MyString(const MyString& other) = delete; // prevent copy constructor

	/*MyString(const MyString&  other)  // swallow copy 
	{
		memcpy(this, &other, sizeof(MyString));
	}*/

	MyString(const MyString& other)  : m_BufferSize(other.m_BufferSize) // deep copy
	{
		m_Buffers = new char[m_BufferSize + 1];

		memcpy(m_Buffers, other.m_Buffers, m_BufferSize + 1);
	}

	~MyString() {
		// we can use smart pointers as well 
		delete[] m_Buffers; // prevent memory leak 
	}

	friend std::ostream& operator<<(std::ostream&, const MyString& str); // lets this function to access to private members

};

std::ostream& operator<<(std::ostream& stream, const MyString& str) {
	stream << str.m_Buffers;
	return stream;

}

struct Vector2 {
	float x;
	float y;
};

int main()
{
	int a = 3;
	int b = a; // create a copy of a , so now we have 2 block of memory ( a , b ) allocated 

	Vector2 v1 = { 2 , 3 };
	Vector2 v2 = v1; // create a copy of a , so now we have 2 block of memory ( v1 , v2 ) allocated 
	v1.x = 4; // wont change v1.x 

	Vector2* v1Ptr = new Vector2{ 2 ,3 };
	Vector2* v2Ptr = v1Ptr; // it wont create a copy of actual vector , we just copy the pointer !! 
	v1Ptr->x = 4; // will change v2Ptr.x 

	{
		MyString myName = MyString("Reza Pouya");
		MyString string = myName;

		//myName[0] = 'P';

		// char* m_Buffers; // is shared between 2 object
		std::cout << myName;
		std::cout << string;

	}
	
	std::cin.get();
}
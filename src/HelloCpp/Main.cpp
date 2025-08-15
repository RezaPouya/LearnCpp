#include "headers/Usings.h"
using namespace Logger;
int main()
{
	std::cout << "Hello World!\n";
	Log("This is my first cpp after so many years","\n");
	Log("================================================================","\n");
	Log("List of Prime numbers: ( 0 , 100000 ) ","\n\n");


	unsigned int i = 1;  // Declare outside the loop for debugging
	Log(2 );
	for (; i < 100000; i = i + 2)
	{
		if (IsPrime(i))
			Log(", ", i);

	}

	Log("\n");
	cin.get();
	return 0;
}
 
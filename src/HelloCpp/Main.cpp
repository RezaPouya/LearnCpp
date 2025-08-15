#include "headers/Usings.h"

int main()
{
	//std::cout << "Hello World!\n";
	LogLine("This is my first cpp after so many years");
	LogLine("================================================================");
	Log("The prime numbers between 0 and 100:" , "\t", 2);

	for (int i = 1; i < 100; i = i + 2)
	{
		if (!IsPrime(i))
			continue;

		Log(", ", i);
	}

	LogLine();
	cin.get();
	return 0;
}

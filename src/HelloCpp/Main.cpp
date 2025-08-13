// HelloCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
//#include "D:/MyGithub/LearnCpp/src/HelloCpp/headers/Logger.h"
#include "E:/Projects/LearnCpp/src/HelloCpp/headers/Logger.h"
#include "E:/Projects/LearnCpp/src/HelloCpp/headers/PMath.h"

int main()
{
	std::cout << "Hello World!\n";
	Log("This is my first cpp after so many years");
	Log("================================================================");
	Log("List of Prime numbers: ");
	unsigned int i = 0;

	bool condition = true;

	for (; condition;)
	{
		//if (IsPrime(i)) {
		//    if (!IsPrimeOrg(i)) {
		//        LogForLoop(i);
		//        Log("  is not ");
		//    }
		//        
		//}

		if (IsPrime(i))
		{
			LogForLoop(i);
		}

		i++;
		if (i > 1000000) {
			condition = 0;
		}
	}
	cin.get(); //std::cin.get();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

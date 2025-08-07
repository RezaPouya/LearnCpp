#include <iostream> // this just copy and past content of this iostream file to this file
#include "Logger.h"
#include <string> 

void Log(const char* message) {
	std::cout << message << std::endl;

	// << are overloaded operator which act like functions
	//std::cout.print(message).print(std::endl);
	//printf("\n");
}


void Log(long  number) {
	std::cout << number << std::endl;
}

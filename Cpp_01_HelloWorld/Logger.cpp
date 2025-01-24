#include <iostream>
#include "Logger.h";
#include <string> 

void Log(const char* message) {
	std::cout << message << std::endl;
}


void Log(long  number) {
	std::cout << number << std::endl;
}

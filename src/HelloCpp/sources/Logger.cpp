#include "../headers/Usings.h"

void Log(const char* message, const char* endline)
{
	std::cout << message << endline;
}

void Log(bigint message, const char* endline)
{
	std::cout << message << endline;
}


void Log(const char* std, bigint message, const char* endline) {
	std::cout << std << message << endline;
}
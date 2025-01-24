// Cpp_01_HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger.h"
#include "Math.h"
#define INTEGER int 

INTEGER main()
{
    Log("Hello World!");
    int i = 10 ;
    unsigned int j = 5; 
    Log(Multiply(i, j));
    std::cin.get();
}
//#include "EndBrace.h"

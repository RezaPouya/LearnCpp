// Cpp_01_HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "Logger.h"
#include "Math.h"
#include "./Ex_01.h"
using namespace std;
#define INTEGER int 

//Caution The main() function must not be defined within a namespace.Things that are not defined in a
// namespace exist in the global namespace, which has no name.

INTEGER main()
{
    Log("Hello World!");
    int i = 10 ;
    unsigned int j = 5; 
    Log(Multiply(i, j));
    Ex_01();
    //std::cin.get();
    cin.get();
}
//#include "EndBrace.h"





#pragma once
#include <iostream>
//#include "E:/Projects/LearnCpp/src/HelloCpp/headers/TypeDefinition.h"

// Use relative path or properly set up include directories in your project
#include "TypeDefinition.h"  // Fixed typo in filename

void Log(const char* message, const char* endline = "\n");
void Log(bigint message, const char* endline = "\n");
void Log(const char* prefix, bigint message, const char* endline = "\n");  // Changed parameter name from std to prefix

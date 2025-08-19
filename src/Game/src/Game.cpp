#include <iostream>
//#include "D:/MyGithub/LearnCpp/src/GameEngineLib/src/Engine.h"
#include "Engine.h"

// ways to include engine.h
// 1- #include "../../GameEngineLib/engine.h"
// 
// 
// 
// 2 
//  - add address via -- C/c++ -> General -> Additional Include Directories: 
//  - vsproject -> Right Click -> Add -> Reference 


int main()
{
    engine::PrintMessage();
    std::cin.get();
}

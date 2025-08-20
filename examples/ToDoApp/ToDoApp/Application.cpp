// ToDoApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//$(SolutionDir)bin\examples\to-do-app\$(ProjectName)\$(Platform)\$(Configuration)\


#include "Manages/CommandManager.h"

// use pointer to function to register all commands from ToDoTaskManager to CommandManagers
int main() {
    CommandManager app;

    // You can override default handlers:
    app.registerCommandHandler(MenuCommand::Add, []() {
        std::cout << "Custom add handler called!\n";
        // Implement actual add logic here
    });

    app.run();
    return 0;
}

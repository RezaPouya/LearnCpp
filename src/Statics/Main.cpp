#include <iostream>
#define Log(x) std::cout << x << std::endl ; 

// 
// int s_Variable = 5;
extern int s_Variable; // external linking its just 

void Function() {

}

// try to  mark your function and variable as static unless you want to link them accross translation units
int main()
{

    std::cout << s_Variable << std::endl;
    std::cout << "Hello World!\n";
    std::cin.get();
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

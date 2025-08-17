#include <iostream>
#include <string>


void PrintStringPassByRef(std::string& str) {

    str = "Print String Pass By Ref  ::: " + str;
    std::cout << str << std::endl;
}

// pass by value  ( copy by value  ) // string copying is very slow 
void PrintString(std::string str) {
    str = "Print String ::: " + str;
    std::cout << str << std::endl;
}

int main()
{
    // string group of characters 

    // c-style string 
    const char* name = "Reza Pouya"; // this is fixed allocated block of memory
    std::cout << name << std::endl;
    std::cout <<  std::endl;
    char secondName[] = { 'R', 'e' , 'z' , 'a' , ' ' , 'P' , 'o' , 'u' , 'y' , 'a' };

    int secondNameSize = sizeof(secondName) / sizeof(char);
    for (int i = 0; i < secondNameSize; i++) {
        std::cout  << secondName[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;
    char thirdName[] = { 'R', 'e' , 'z' , 'a' , ' ' , 'P' , 'o' , 'u' , 'y' , 'a' };

    std::cout << thirdName << std::endl;

    std::cout << std::endl;
    char fourthName[] = { 'R', 'e' , 'z' , 'a' , ' ' , 'P' , 'o' , 'u' , 'y' , 'a' , 0 };

    std::cout << fourthName << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::string str = "Reza Pouya From string"; // this is basically const char* which bunch of method to manipulate it.

    std::cout << str << std::endl;
    std::cout << "size : " << str.size() << std::endl;
    

    str = str + " concated";

    std::cout << str << ". size " << str.size() << std::endl;


    //std::string str2 = "Value " + "Value "; // it wont work ;
    std::string str2 = "Value " ; // it wont work ;
    str2 += " value";
    std::cout << str2 << ". size " << str2.size() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::string str3 = std::string( "Value ") + "zendegi"; // it wont work ;
    std::cout << str3 << ". size " << str3.size() << std::endl;

    // find() is position of first character of searched strings.
    bool contains = str.find("zen") != std::string::npos; // no pose is illigal position , 

    PrintString(str);
    PrintStringPassByRef(str);
    std::cout << str <<   std::endl;


    std::cin.get();
}


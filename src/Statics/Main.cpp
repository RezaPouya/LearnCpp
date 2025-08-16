#include <iostream>


// int s_Variable = 5;
extern int s_Variable; // external linking its just 

void Function() {

};

struct Entity {
    static int x;
    static int y;
    int a;
    int b;

    void print(const char* entityName) {
        std::cout << entityName << ": " << Entity::x << "," << Entity::y << std::endl;
    }
};

// in C++, static member variables must be both declared inside the class and defined outside of it.
int Entity::x = 0;  // Must appear exactly once in the program
int Entity::y = 0;


static void print_static(const Entity& entity) {
    std::cout << "Static Call" << ": " << entity.a << "," << entity.b << std::endl;
}

// try to  mark your function and variable as static unless you want to link them across translation units
int main()
{

    std::cout << s_Variable << std::endl;
    Entity entity01;
    entity01.a = 5;
    entity01.b = 10;
    Entity::x = 14;
    Entity::y = 72; 

    //Entity entity02 = {  3 , 4 };

    Entity entity02;
    entity02.a = 12;
    entity02.b = 87;
    Entity::y = 32;

    entity01.print("entity-01");
    entity02.print("entity-02");
    print_static(entity01);
    print_static(entity02);

    std::cin.get();
}



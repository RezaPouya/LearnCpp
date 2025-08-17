#include <iostream>

// Forward declarations
class Entity;
void Printble(const Entity* entity);
void Printble2(const Entity& entity);

class Entity {
public:
    int x{}, y{};  // Value initialization to 0

    void SetX(int x, int y) {
        this->x = x;        // Correct use of 'this'
        (*this).x = x;      // Works but redundant
        this->y = y;

        Entity* const e = this;  // Correct
        e->x = x;            // Valid
    }

    int GetX() const {
        return this->x;      // Good

        // const correctness enforced:
        const Entity* e = this;  // Correct in const method
        return e->x;
    }

    void Print() const {
        Printble(this);     // Passes pointer to current object
        Printble2(*this);   // Passes reference to current object
    }
};

void Printble(const Entity* entity) {
    std::cout << "Printble(const Entity* entity) is called\n";
}

void Printble2(const Entity& entity) {
    std::cout << "Printble(const Entity& entity) is called\n";
}

int main()
{
    // this keyword is only accessible to member function 
    // pointer to current object instance of class 

    Entity entity;
    entity.Print();

    std::cout << "Hello World!\n";
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

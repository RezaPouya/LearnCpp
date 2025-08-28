#include <iostream>


class Base {
    //dynamic_cast requires polymorphic classes(at least one virtual function)
public:
    Base() {}
    ~Base() {}

    virtual const char* GetTypeName() { return "Base"; };
};

class Derived : public Base {
public:
    Derived() {}
    ~Derived() {}

     const char* GetTypeName() override { return "Derived"; };
};


class AnotherClass : public Base {
public:
    AnotherClass() {}
    ~AnotherClass() {}


    const char* GetTypeName() override { return "AnotherClass"; };
};

int main()
{
    double a = 5.3f;
    auto b = (int)a; // c style cast

    std::cout << b << std::endl;


    double a2 = 5.3f;
    auto b2 = static_cast<int>(a2); // static cast , fastest 
    // auto b2 = static_cast<AnotherClass*>(a2); // check on compile  -- invalid type conversion
    auto b3 = reinterpret_cast<AnotherClass*>(&a2); // reinterpret_cast 

    // const_cast is used to add or remove const (and volatile) qualifiers from variables.
    int nonConstValue = 42;
    const int& constRef = nonConstValue; // Const reference to non-const variabl
    // Safe: removing const from reference to originally non-const variable
    int& nonConstRef = const_cast<int&>(constRef);
    nonConstRef = 100;



    //-------------------------------------------------------
    Derived* derived = new Derived(); // create on heap , new actually call malaloc
    Base* base = derived ; 

    AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
    if (ac) {
        std::cout << "base is another class";
    }
    else {
        std::cout << "ac is null because the dynamic cast is failed ";
    }
    std::cin.get();
}


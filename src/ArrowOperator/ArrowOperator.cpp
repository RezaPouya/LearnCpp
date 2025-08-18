#include <iostream>
#include <string>
#include <format>



class Entity {
private:
    std::string m_name;

public:
    Entity() : m_name("UnKnown") {};

    explicit Entity(const std::string& name) : m_name(name) {
        std::cout << std::format("Entity '{}' created\n", m_name);
    }

    ~Entity() noexcept {
        std::cout << std::format("Entity '{}' destroyed\n", m_name);
    }

    std::string GetName() const {
        return m_name;
    }

    void Print() const {
        // do nothing 
    }
};

class ScopedPointer {
    Entity* m_entity;
   
public :

    ScopedPointer(Entity* entity) :m_entity(entity){}
    ~ScopedPointer() {
        delete m_entity;
    }

    Entity* GetObject() { return m_entity; }
    const Entity* operator->() const { return m_entity; }
};

struct Vector3 {
    float x;
    float y;
    float z;
};


int main()
{
    Entity entity;
    entity.Print();

    Entity* ptr = &entity;;

    (*ptr).Print();
    ptr->Print(); // defaut usecase for arrow operator  

    //----------------------------------------------------

    ScopedPointer scopedPtr = new Entity();
    scopedPtr.GetObject()->GetName(); // not pretty 
    scopedPtr->GetName(); // operator overloading 

    //----------------------------------------------------

    // have usage in serialization and graphic programing ( becuase we dealing with stream of bytes )
    &((Vector3*)0)->x;
    int offset = (int)(&((Vector3*)0)->x);

    std::cout <<  "&((Vector3*)0)->x: " << &((Vector3*)0)->x << std::endl;
    std::cout <<  "&((Vector3*)0)->y: " << &((Vector3*)0)->y << std::endl;
    std::cout <<  "&((Vector3*)0)->z: " << &((Vector3*)0)->z << std::endl;

    std::cout << "&((Vector3*)nullptr)->x: " << &((Vector3*)nullptr)->x << std::endl;
    std::cout << "&((Vector3*)nullptr)->y: " << &((Vector3*)nullptr)->y << std::endl;
    std::cout << "&((Vector3*)nullptr)->z: " << &((Vector3*)nullptr)->z << std::endl;


    std::cout << "offset (int)(&((Vector3*)nullptr)->x) : " << (int)(&((Vector3*)nullptr)->x) << std::endl;
    std::cout << "offset (int)(&((Vector3*)nullptr)->y) : " << (int)(&((Vector3*)nullptr)->y) << std::endl;
    std::cout << "offset (int)(&((Vector3*)nullptr)->z) : " << (int)(&((Vector3*)nullptr)->z) << std::endl;
    std::cin.get();
}

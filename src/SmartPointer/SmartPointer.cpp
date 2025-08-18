#include <iostream>
#include <string>
#include <format>
#include <memory>


// Smart pointer are for automating use of new and delete keyword
// its for not using new and  delete 
// its essentially a wrapper around raw-pointer 
// kind of smart pointer 
//  - unique pointer : its scoped pointer ( after pointer leave scope , its delete ) 
//          - its should be unique and cannot be copied 
//          - it has very small overhead and is fast 
//  - shared pointer : its use reference counter , if reference counter goes down to zero , its free memory
//          - have some overhead 
//  - weak pointer: is copied shared pointer which doesn't increase ref count !! 

// use it as much as possible 



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
};


int main()
{

    { // this is a scope
        std::unique_ptr<Entity> entity(new Entity("unique pointer 01 "));
        std::cout << entity->GetName() << std::endl;
    }

    // auto act live 'var' in C#
    { // preferred way of assigning unique pointer 
        // make_unique() is for exception safety
        auto entity = std::make_unique<Entity>(new Entity("unique pointer 02"));
        std::cout << entity->GetName() << std::endl;
    }

    { 
        auto entity = std::make_unique<Entity>(new Entity("unique pointer 03"));
        //std::unique_ptr<Entity> e0 = entity; // we cannot copy unique pointer 
    }

    {
        // never do these with shared pointer ( never use new keyword ) 
          //auto entity = std::shared_ptr<Entity>(new Entity("share pointer 01"));
          //auto entity = std::make_shared<Entity>(new Entity("share pointer 01"));
        std::shared_ptr<Entity> e0;

        {
            // shared pointer need to allocate new block of memory called the 'control-block' to keep reference count 
            // if you use new keyword , you have 2 allocation which is not efficient
            auto sharedEntity = std::make_shared<Entity>("shared_pointer_01");
            auto e02 = sharedEntity;
            std::weak_ptr<Entity> weakPtr = sharedEntity; // its copy but not increase ref count  -- it won't keep it alive 

            //if(!weakPtr.expired()) // you can check if its expired or not 
        }
    }
    

    std::cout << "Hello World!\n";
}
 
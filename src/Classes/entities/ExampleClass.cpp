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
};
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

class MyString {
private:
    size_t m_Size = 0;
    std::unique_ptr<char[]> m_Buffer;

public:
    explicit MyString(const char* str) {
        if (!str) throw std::invalid_argument("Null string provided");

        m_Size = std::strlen(str);
        m_Buffer = std::make_unique<char[]>(m_Size + 1);  // +1 for null terminator
        std::memcpy(m_Buffer.get(), str, m_Size);
        m_Buffer[m_Size] = '\0';  // Ensure null termination
    }

    // No need for destructor - unique_ptr handles cleanup!

    // Copy constructor
    MyString(const MyString& other) : m_Size(other.m_Size), m_Buffer(std::make_unique<char[]>(other.m_Size + 1)) {
        std::memcpy(m_Buffer.get(), other.m_Buffer.get(), m_Size + 1);
    }

    // Move constructor
    MyString(MyString&& other) noexcept : m_Size(other.m_Size), m_Buffer(std::move(other.m_Buffer)) {
        other.m_Size = 0;
    }

    // Copy assignment
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            auto newBuffer = std::make_unique<char[]>(other.m_Size + 1);
            std::memcpy(newBuffer.get(), other.m_Buffer.get(), other.m_Size + 1);
            m_Buffer = std::move(newBuffer);
            m_Size = other.m_Size;
        }
        return *this;
    }

    // Move assignment
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            m_Buffer = std::move(other.m_Buffer);
            m_Size = other.m_Size;
            other.m_Size = 0;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        return os << str.m_Buffer.get();
    }

    // Access methods
    const char* c_str() const { return m_Buffer.get(); }
    size_t size() const { return m_Size; }
    bool empty() const { return m_Size == 0; }
};

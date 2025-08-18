#include <iostream>
#include <iostream>
#include <mutex>


// 
// int s_Variable = 5;
extern int s_Variable; // external linking its just 

void Function() {
    static int i = 0; // only initialize in first run 
    i++;
    std::cout << i << std::endl;
}

// old way
//class SingletonLogger {
//private:
//    static SingletonLogger* s_instance;
//    int m_logCounterCall;
//
//public:
//    SingletonLogger() : m_logCounterCall(0) {}
//
//    static SingletonLogger& Get() {
//        if (!s_instance) {
//            s_instance = new SingletonLogger();  // Initialize if null
//        }
//        return *s_instance;
//    }
//
//    void Write(const char* message)  {
//        m_logCounterCall++;
//        std::cout << "[LOG]: " << message << std::endl;
//    }
//    int GetCountOfCall() {
//        return m_logCounterCall;
//    }
//};
//
//SingletonLogger* SingletonLogger::s_instance = nullptr;

class SingletonLogger {
private:
    int m_logCounterCall;
    SingletonLogger() : m_logCounterCall(0) {}

public:
    static SingletonLogger& Get() {
        static SingletonLogger logger; // local static 
        return logger;
    }

    void Write(const char* message) {
        m_logCounterCall++;
        std::cout << "[LOG]: " << message << std::endl;
    }

    int GetCountOfCall() {
        return m_logCounterCall;
    }
};

// try to  mark your function and variable as static unless you want to link them across translation units
int main()
{
    std::cout << s_Variable << std::endl;
    SingletonLogger::Get().Write("1 log");
    SingletonLogger::Get().Write("2 log");
    SingletonLogger::Get().Write("3 log");
    SingletonLogger::Get().Write("4 log");
    std::cout << "[LOG-Counter]: " << SingletonLogger::Get().GetCountOfCall() << std::endl;
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
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

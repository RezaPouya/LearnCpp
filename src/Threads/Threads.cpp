#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <format>

static bool is_Finished = false;

void DoWork() 
{
    using namespace std::literals::chrono_literals;

    std::cout <<  std::format("started thread id : {} \n" , std::this_thread::get_id()) ;

    while (!is_Finished) {
        std::cout << "working....\n";
        std::this_thread::sleep_for(250ms);
        ;
    }
}

int main()
{

    std::cout << std::format("started thread id : {} \n", std::this_thread::get_id());
    std::thread worker(DoWork);
    
    auto x = std::cin.get();
    is_Finished = true;


    worker.join(); // wait thread to join up  ( like wait in C# )
 

    std::cout << std::format("started thread id : {} \n", std::this_thread::get_id());
    std::cin.get();
}

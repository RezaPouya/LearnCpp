#include <iostream>
#include <chrono>
#include <string>
#include <format>
#include <memory>    // Added for smart pointers
#include <array>     // Added for std::array
#include <algorithm>
#include <vector>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;

public:
    Timer() : m_StartTimePoint(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        Stop();
    }

    void Stop() noexcept {
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
        auto duration = end - start;

        double milliSeconds = duration * 0.001;  // Fixed: microseconds to milliseconds

        std::cout << std::format("Elapsed time {:.3f} ms.\n", milliSeconds);  // Fixed format
    }
};

void FirstExample() {
    
    int value = 0;
    {
        Timer timer;
        for (int i = 1; i <= 10000000; i++) {
            value += 2;
        }
    }

    std::cout << "Value: " << value << "\n";
    // in reality , compiler in release mode will actually 
    // compute this function and put 20000000 in value and 
    // the for loop never run 
}

void SecondExample() {
    struct Vector2 { float x, y; };

    std::cout << "Check Shared Pointers\n";
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        std::cout << "make_shared: ";
        for (int i = 0; i < sharedPtrs.size(); i++) {
            sharedPtrs[i] = std::make_shared<Vector2>();
        }
    }

    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer;
        std::cout << "new: ";
        for (int i = 0; i < sharedPtrs.size(); i++) {
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }

    std::cout << "Check Unique Pointers\n";
    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer timer;
        std::cout << "make_unique: ";
        for (int i = 0; i < uniquePtrs.size(); i++) {
            uniquePtrs[i] = std::make_unique<Vector2>();
        }

        std::ranges::for_each(uniquePtrs, 
            [](std::unique_ptr<Vector2>& uPtr) {
                uPtr = std::make_unique<Vector2>();
            });
    }

    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer timer;
        std::cout << "unique_ptr (new): ";

        for (int i = 0; i < uniquePtrs.size(); i++) {
            uniquePtrs[i] = std::unique_ptr<Vector2>(new Vector2());
        }
    }
}

int main() {
    FirstExample();
    SecondExample();

    // Platform-independent debug break
#if defined(_MSC_VER)
    __debugbreak();
#else
    asm("int3");  // GCC/Clang equivalent
#endif
}
#include <iostream>
#include <tuple>
#include<vector>
#include<array>
#include <functional>
#include <algorithm>

// whenever you have function pointer , you can use lambda 


//template<typename std::vector<T,TSize> vectors, typename void(*func)(P)>
//void ForEach(std::vector<T, TSize> vectors, U) {
//    for (auto t : T)
//        U();
//}

class Counter {
private:
	int m_Id = 0;
public:
	Counter() {
		static int counter = 1000;
		m_Id = ++counter;
	}
	const int GetId() const { return m_Id; }
};

template<typename T>
void Print(T p) {
	std::cout << p << "\n";
}

void forEach(const std::array<int, 3>& values, void(*func)(int p)) {
	std::cout << "\nforeach" << "\n";
	for (auto v : values) {
		func(v);
	}
}


void forEach2(const std::array<int, 3>& values, const std::function<void(int)>& func) {
	std::cout << "\nforeach2" << "\n";
	for (auto v : values) {
		func(v);
	}
}


// More flexible version using std::function
template<class T, size_t TSize, class Func>
void ForEach(const std::array<T, TSize>& values, Func func) {
	for (auto v : values) {
		func(v);
	}
}

// C++20 concept version
template<typename T, size_t N, std::invocable<const T&> Func>
void ModernForEach(const std::array<T, N>& values, Func func) {
	for (auto v : values) {
		func(v);
	}
}



void PrintReference(const Counter& p) {
	std::cout << p.GetId() << "\n";
}


int main()
{

	// static array 
	std::array<int, 3> data = { 1,2,3 };
	
	auto i = std::find_if(data.begin(), data.end(), [](int value) {
		return value > 1; // return first founded value 
		});

	std::cout << "===============================================\n";
	std::cout << *i << std::endl;
	std::cout << "===============================================\n";
	void(*funcP)(const Counter& t)  = PrintReference;

	forEach(data, [](mutable int value) { 
		Print(value);  
		value = 444;  
		});

	forEach(data, Print );
	forEach2(data, [](mutable int value) {
		Print(value);
		value = 444;
		});



	Counter c1, c2, c3;
	std::array<const Counter, 3> data2 = { c1 , c2 , c3 };

	ForEach(data2, PrintReference);

	// [] capture , list of comma seperated 
	// [=] capture all by value 
	// [&] capture all by reference 
	// [= , &b] , capture all by value , capture b by reference 
	ModernForEach(data2, [](Counter p) {std::cout << p.GetId() << "\n"; });

	std::cin.get();
}

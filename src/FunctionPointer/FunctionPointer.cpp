#include <iostream>
#include <tuple>
#include<vector>
#include<array>
#include <functional>

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
	for (auto v : values) {
		func(v);
	}
}

template<class T , size_t TSize>
void PrintForEach(const std::array<const T, TSize>& values , void(*funcP)(const T& t)) 
{
	for (auto v : values) {
		funcP(v);
	}
  // do nothing
}

//template<class T, int TSize, class P >
//void ForEach(const std::array<T, TSize>& values, void(*func)(P)) {
//
//	for (auto v : values) {
//		func(v);
//	}
//}

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
	
	void(*funcP)(const Counter& t)  = PrintReference;

	forEach(data, [](int value) { Print(value); });
	forEach(data, Print );


	Counter c1, c2, c3;
	std::array<const Counter, 3> data2 = { c1 , c2 , c3 };

	PrintForEach(data2, PrintReference);
	ModernForEach(data2, [](Counter p) {std::cout << p.GetId() << "\n"; });

	std::cin.get();
}

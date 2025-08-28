#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "Vector.h"
#include <algorithm>

struct Vertex {
    float x, y, z;
    Vertex(float x , float y , float z) : x(x) , y(y) , z(z){}

    Vertex(const Vertex& other) :x(other.x), y(other.y), z(other.z) { // copy constructor
        std::cout << "Vertex Copied\n";
    }


    float* GetAsArray() {
        return &x; // pointer to firest element !!! 
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
    stream << "( " << vertex.x << " , " << vertex.y << " , " << vertex.z << " )";
    return stream;
}


void VectorBasic()
{
    std::vector<Vertex> vertices;
    vertices.push_back({ 1,4,3 });
    vertices.push_back({ 2,4,3 });
    vertices.push_back({ 3,4,3 });

    vertices.erase(vertices.begin() + 1); // remove second element 

    //for (int i = 0; i < vertices.size(); i++) {
    //    std::cout << vertices[i] << std::endl;
    //}

    for (const Vertex& v : vertices) {
        std::cout << v << std::endl;
    }

    vertices.erase(vertices.begin() + 1); // remove second element 

    vertices.clear();
}


void VectorOptimization()
{
    std::vector<Vertex> vertices;
    vertices.reserve(3);
    //vertices.push_back(Vertex( 1,4,3 )); // now this vertex is created in this scoped then copied to vertecies dynamic array list
    //vertices.push_back({ 2,4,3 });
    //vertices.push_back({ 3,4,3 });

    vertices.emplace_back(1, 4, 3); // now this vertex is created in this scoped then copied to vertecies dynamic array list
    vertices.emplace_back(2, 4, 3);
    vertices.emplace_back(3, 4, 3);

    vertices.erase(vertices.begin() + 1); // remove second element 

    //for (int i = 0; i < vertices.size(); i++) {
    //    std::cout << vertices[i] << std::endl;
    //}

    for (const Vertex& v : vertices) {
        std::cout << v << std::endl;
    }

    vertices.clear();
}




//using DynamicArray = std::vec<>
// vector are in reality Dynamic array like List<T> in C# 
int main()
{
    //VectorBasic();
    VectorOptimization();


    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "Sorting" << std::endl;


    std::vector<int> arrayList = { 3,5,7,98,9,945,1,1324 };
    for (auto i : arrayList) {
        std::cout << i << ", ";
    }

    std::cout << std::endl << "default sorting" << std::endl;

    std::sort(arrayList.begin(), arrayList.end());

    for (auto i : arrayList) {
        std::cout << i << ", ";
    }


    std::cout << std::endl << "greater than than sorting" << std::endl;

    std::sort(arrayList.begin(), arrayList.end(), std::greater<int>());

    for (auto i : arrayList) {
        std::cout << i << ", ";
    }


    std::cout << std::endl << "lesser than than sorting" << std::endl;

    std::sort(arrayList.begin(), arrayList.end(), [](int a, int b) {
        return (a < b) ? true : false;

        });

    for (auto i : arrayList) {
        std::cout << i << ", ";
    }


    std::cout << std::endl << "send a to end of list " << std::endl;

    std::sort(arrayList.begin(), arrayList.end(), [](int a, int b)
        {
            if (a == 3)
                return false;

            if (b == 3)
                return true;

            return a < b;
        });

    for (auto i : arrayList) {
        std::cout << i << ", ";
    }



    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "Type punning" << std::endl;
    std::cout << std::endl << "size of flout " << std::endl;


    Vertex e(3.4f, 2.3f, 53.9f);

    const float* position = (float*)&e;

    std::cout << "Type punnining  Vertex e(3.4f, 2.3f, 53.9) with  float* position = (float*)&e; ==> " 
        << position[0] << ", " << position[1] << ", " << position[2]
        << std::endl;

    const float z = *((float*)&e + 2 );

    std::cout << "Type punnining  Vertex e(3.4f, 2.3f, 53.9) with  const float z = *((float*)&e + 2 ); ==> "
        << z << std::endl;



    std::cout << "Type punnining Vertex e(3.4f, 2.3f, 53.9)  get e.GetAsArray()[1]  : should return 2.3  ==> "
        << e.GetAsArray()[1] << std::endl;

    std::cin.get();
}

 
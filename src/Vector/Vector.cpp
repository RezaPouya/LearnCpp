#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "Vector.h"

struct Vertex {
    float x, y, z;
    Vertex(float x , float y , float z) : x(x) , y(y) , z(z){}

    Vertex(const Vertex& other) :x(other.x), y(other.y), z(other.z) { // copy constructor
        std::cout << "Vertex Copied\n";
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

    vertices.erase(vertices.begin() + 1); // remove second element 

    vertices.clear();
}




//using DynamicArray = std::vec<>
// vector are in reality Dynamic array like List<T> in C# 
int main()
{
    //VectorBasic();
    VectorOptimization();

    std::cin.get();
}


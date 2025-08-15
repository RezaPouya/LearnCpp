#include <iostream>
#define Log(x) std::cout << x << std::endl ; 

int main()
{
    Log( "Hello Raw Pointers!");
    Log("");
    Log( "Pointers are just integer which store address of memory!");
    Log("");
    Log("* : to specify a pointer variable. ex: void* ptr = nullptr");
    Log("$ : to get memory address of a variable. ex: void* ptr = &someVariable");
    Log("*before a pointer variable : de-referencing a point access to value of a it , we can get or set it. ex: std::cout << *ptr << std::endl");
    Log("");

    void* ptr = nullptr;  // void* mean the pointer is completely type-less
    Log("");

    void* ptr2 = 0;  // zero is not valid memory address , its a way in legacy code to show null pointer 

    int var = 8;
    Log(var);

    void* voidPtr = &var; // we are assigning the memory address of 'var' to 'varPtr' 
    int* intPtr = &var; // we are assigning the memory address of 'var' to 'varPtr' 
    *intPtr = 1; // de-referencing the pointer and accessing to its value ( here we set a value to it ) 
    
    //*voidPtr = 10;  // we cannot assign a value to void pointer 
    
    Log(voidPtr);
    
    Log(*intPtr); // // de-referencing the pointer and accessing to its value ( here we just show it ) 
    
    // notes: pointers are stored in stack


    // now we are creating a variable on the heap which allocate 8 bytes of memory for us ( char = 1 byte ) and point to first byte
    char* buffers = new char[8]; 

    char** ptrToBuffers = &buffers; // pointer to a pointer 

    // memset() fills a block of memory with data we specify 
    memset(buffers, 0, 8);

    Log(buffers);

    // now because we use 'new' keyword and this data is heap allocated , we should delete it  to free memory
    
    delete[] buffers; // here we are using delete keyword and because its array , we add [] after delete keyword.

    // final note : pointers are just variables
 

    std::cin.get();
}

 

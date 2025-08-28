#include <iostream>
#include <array>
#include <memory>
#include <vector>
#include <algorithm>

// what is arrays : arrays are basically collection of elements in particular order 

void firstArrayExample() {
    short primeNumbersUnderTen[4];
    primeNumbersUnderTen[0] = 2;
    primeNumbersUnderTen[1] = 3;
    primeNumbersUnderTen[2] = 5;
    primeNumbersUnderTen[3] = 7;

    int a = primeNumbersUnderTen[0];

    // note beaware of memory access violation primeNumbersUnderTen[12]

    std::cout << "array itself is just pointer to first element of array " << primeNumbersUnderTen << std::endl ;
    std::cout << "we can access to array element by index primeNumbersUnderTen[2] ( 3rd element of array ) : " << primeNumbersUnderTen[2] << std::endl ;


    short primeNumbersUnder20[8] = { 2,3,5,7,11,13,17,19 };

    int arrayCount = sizeof(primeNumbersUnder20) / sizeof(short);

    std::cout << "prime number under 20 are " << arrayCount << std::endl;

    for (int i = 0; i < arrayCount; i++) {
        std::cout << i <<  " : " << primeNumbersUnder20[i] << std::endl;
    }
}


void MultiDimensioalArrays() {

    int** twoDimensionalArray = new int*[5];
    
    for (int i = 0; i < 5; i++) {
        twoDimensionalArray[i] = new int[20];

        for (size_t j = 0; j < 20; j++)
        {
            twoDimensionalArray[i][j] = i + j;
        }
    }

    std::vector<std::array<int, 5>> t2Array;
    for (auto v : t2Array) {
        for (auto v2 : v) {
            v2 = 2;
        }
    }


    /// we can save multi dimensional array in noraml arays 

     auto cartasianPoints5x5 = new int[25];

     int j = 0;
     for (int i = 0; i < 5; i++)
     {
         for (int j = 0; j < 5; j++)
             cartasianPoints5x5[i + j * 5] = (j * 5) + i;
     }

     for (int i = 0; i < 25; i++)
         std::cout << cartasianPoints5x5[i] << ", ";

     std::cout << "\n";

}


void secondArrayExample() {

    short naturalNumber[100];
     
    short* arrayPtr = naturalNumber;

    for (int i = 0; i < 100; i++) {
        naturalNumber[i] = i + 1;
    }

    naturalNumber[99] = 1000; 

    std::cout << std::endl << "naturalNumber[99] = 1000   => naturalNumber[99] ==> " << naturalNumber[99] << std::endl;

    // this is pointer arithmetic , the number added to pointer is base on type size 
    *(arrayPtr + 99) = 10001;

    std::cout << std::endl << "*(arrayPtr + 99) = 10001   => naturalNumber[99] ==> " << naturalNumber[99] << std::endl;


    // arays are just continues block of data which we can access via pointer 
    *(short*)((char*)arrayPtr + 198) =  99;


    std::cout << std::endl << " *(short*)((char*)arrayPtr + 198) =  99   => naturalNumber[99] ==> " << naturalNumber[99] << std::endl;
     
}

void thirdExampleArraysOnTheHeap() {

    int example[5];

    for (int i = 0; i < 5; i++) {
        example[i] = i + 1;
    }

    // this array is created on the heap 
    int* anotherArray = new int[5];

    // the life time of these 2 arrays are diffrent , the first one is on the stack which will destroyed after the end of 
    // context ( exit from function ) , the second one live on the heap which we should destroy it manually.

    // we use new for returning an array 
    for (int i = 0; i < 5; i++) {
        anotherArray[i] = i + 1;
    }

    delete[] anotherArray;
}

class MemoryFragmentation {

public:
    static const int heapArraySize = 5; 
    
    int example[5];

    int* heap = new int[heapArraySize]; // this is just ptr to actual array block
    
    int heapArrayCount;

    MemoryFragmentation() {

        for (int i = 0; i < 5; i++) {
            example[i] = i + 1;
        };

        for (int i = 0; i < heapArraySize; i++) {
            heap[i] = i + 1;
        }

        heapArrayCount = heapArraySize;//  sizeof(heap) / sizeof(int); // it wont work for heap array , we should maintain the size manually 
    }
};

int main()
{
    firstArrayExample();
    
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<  std::endl;
    
    secondArrayExample();
    
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    
    thirdExampleArraysOnTheHeap();

    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
   
    MemoryFragmentation mf;


    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    
    std::array<int, 100> array;

    for (int i = 0; i < array.size(); i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << ", ";
    }

    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;   std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    MultiDimensioalArrays();

    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << "Sorting" << std::endl;


    std::vector<int> arrayList = {3,5,7,98,9,945,1,1324};
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

    std::cin.get();
}



#include <iostream>
#define Log(x) std::cout << x << std::endl ; 


void increment(int a) {
	a = a + 1;
}


// pass the pointer 
void incrementBySendingThePointer(int* a) {
	//*a = *a + 1;
	(*a)++;
}

// pass by reference - its just syntax sugger
void incrementByRef(int& a) {
	a = a + 1;
}



int main()
{
	Log("References");
	Log("");
	Log("References are just pointer in disguise, for computers its just like pointers , for us there are some semantic differences!");
	Log("A reference is a way to referencing EXISTING variable!");
	Log("A reference is not a variable and doesn't take memory!");
	Log("int& : & is part of type and the meaning is depend to the context ");
	Log("int& refToA = a; : 'refToA'  is actually an allias to variable 'a' not new variable !! its just in source code and wont exists in compiled code");
	Log("");

	int a = 5;
	int& refToA = a; //
	Log(refToA);
	refToA = 2;
	Log(refToA);
	Log("");


	increment(a);
	Log("a after we called 'increment(a)', the result of 'Log(refToA)' is:");
	Log(refToA);
	Log("it didn't show incremented value because we send the parameter by value and it create another copy of it an increase the local copy ");
	Log("");
	incrementByRef(a);
	Log("");
	Log("a after we called ' incrementByRef(a)', the result of 'Log(refToA)' is:");
	Log(refToA);
	Log("a after we called 'void incrementByRef(int& a)' by'ncrementByRef(a)', the result of 'Log(refToA)' is:")

	Log("");
	incrementBySendingThePointer(&a);
	Log("");
	Log("a after we called ' incrementBySendingThePointer(a)', the result of 'Log(refToA)' is:");
	Log(refToA);
	Log("a after we called 'void incrementBySendingThePointer(int* a)' by' incrementBySendingThePointer(&a)', the result of 'Log(refToA)' is:")
	Log("");

	int b = 5;
	int c = 6;
	int& ref = c;
	Log(ref);
	ref = b; // its just make c = value of b 
	Log(ref);
	Log(b);
	Log("");

	// when you declare a reference , you need to assign it to something. 


	// we can do this :
	int* refA = &a;
	refA = &b;
	std::cin.get();
}


// Ex1_01.cpp - A complete C++ program
//import std; // This line makes the entire Standard Library available,
#include <iostream>
#include <print>
// including the std::println() functionality used below


int Ex_01()
{
	int answer{ 42 }; // Defines the variable answer with value 42
	std::println("The answer to life, the universe, and everything is {}.", answer);

	// In general, you can use any number of replacement fields, and you can add format specifiers to the
	// replacement fields to override the default formatting scheme.
	// {:!^12b} In reality, this format specifier instructs std::println() to output answer as a binary number(b), centered(^)
	// in a field that is 12 characters wide, filling the remainder of the thus overly wide field with exclamation
	// marks(!).
	std::println("The answer to {} is {:!^12b}", "the ultimate question", answer);
	std::println("The answer to {} is {:b}", "the ultimate question", answer);

	std::print("The answer to life, ");
	std::print("the universe, ");
	std::print("and everything ");
	std::println("is {}", answer);

	// Unlike in several other programming languages, you cannot invoke std::print() or
	// std::println() without a format string.That is, you cannot, for instance, use std::println(value) to
	// output only the value of answer.Instead, you use statements of the form std::println("{}", value).You
	// also cannot invoke std::println() without an argument to output a line break, and nothing else.Instead,
	// you use either std::println("") or std::print("\n").

	return 0;
}





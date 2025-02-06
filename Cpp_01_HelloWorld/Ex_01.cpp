
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



void Ex_02_Variables() {
	int apple_count{ 15 }; // Number of apples
	int orange_count{ 5 }; // Number of oranges
	int total_fruit{ apple_count + orange_count }; // Total number of fruit
	std::println("The value of apple_count is {}", apple_count);
	std::println("The value of orange_count is {}", orange_count);
	std::println("The value of total_fruit is {}", total_fruit);

	unsigned int yards{}, feet{}, inches{};
	// Convert a distance in yards, feet, and inches to inches
	std::print("Enter a distance as yards, feet, and inches ");
	std::println("with the three values separated by spaces: ");
	std::cin >> yards >> feet >> inches;
	const unsigned feet_per_yard{ 3 };
	const unsigned inches_per_foot{ 12 };
	unsigned total_inches{};
	total_inches = inches + inches_per_foot * (yards * feet_per_yard + feet);
	std::println("This distance corresponds to {} inches.", total_inches);
	// Convert a distance in inches to yards, feet, and inches
	std::print("Enter a distance in inches: ");
	std::cin >> total_inches;
	
	feet = total_inches / inches_per_foot;
	inches = total_inches % inches_per_foot;
	yards = feet / feet_per_yard;
	feet = feet % feet_per_yard;
	std::println("This distance corresponds to {} yards {} feet {} inches.",
		yards, feet, inches);
}



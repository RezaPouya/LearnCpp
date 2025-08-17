#include <iostream>
#include <string>
#include <string_view>

using String = std::string;


void Ex01()
{
	// string is stored in const segment, its read only memory
	String str = "Reza";
	const char* constChar = "Reza";
	strlen(constChar);
	str.length();

	const char* utf8 = u8"Utf-8";
	const wchar_t* whiteChar = L"Utf-8";
	const char16_t* utf16 = u"utf16";
	const char32_t* utf32 = U"utf16";
}


void Ex02()
{
	using namespace std::string_literals;
	String name = String("Reza") + "Pouya";
	std::string name2 = "Reza"s + "Pouya"; // "Reza"s is possible due string_literals
}


void Ex03()
{
	const char* lines = R"(line 1 
		line 2 
		line 3)"; // prantese are mandatory


	const char* ex = "line 1 \n"
		"line 2  \n"
		"line 3 \n"; // prantese are mandatory
}
#include <iostream>
#include <tuple>

struct FullNameDto {
    std::string FirstName;
    std::string LastName;
    short Age;
    FullNameDto(std::string fname , std::string lname , short age) : FirstName(fname) , LastName(lname) , Age(age){}
};

struct FullName {
private: 
    std::string fname;
    std::string lname;
    short age;

public:

    FullName(std::string fname, std::string lname, short age) : fname(fname), lname(lname), age(age) {}

    std::tuple<std::string, std::string> GetName() {
        return std::make_pair(fname, lname);
    }

    std::pair<std::string, std::string> GetNameAsPair() {
        return std::make_pair(fname, lname);
    }

    FullNameDto GetDto() {
        FullNameDto dto(fname, lname, age);
    }

    const void Print() {
        std::cout << fname << " " << lname << " - " << age;
    }

    static void Print(const std::tuple<std::string, std::string> tp)  {
        std::cout << std::get<0>(tp) << " " << std::get<0>(tp) ;
    }
};

std::tuple<std::string, std::string> GetName();

int main()
{
    FullName person("Reza", "Pouya", 35);
    person.Print();

    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

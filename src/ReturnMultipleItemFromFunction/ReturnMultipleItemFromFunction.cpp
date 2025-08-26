#include <iostream>
#include <tuple>

struct ResultDto {
    std::string FirstName = {};
    std::string LastName = {};

    ResultDto(std::string fn, std::string ln) : FirstName(fn), LastName(ln) {}
};

std::tuple<std::string, std::string> ReturnFromTuple() {

    std::string fName("Reza");
    std::string lName("Pouya");

    return std::make_pair(fName, lName);
}

std::pair<std::string, std::string> ReturnFromPair() {

    std::string fName("Reza");
    std::string lName("Pouya");

    return std::make_pair(fName, lName);
}

const ResultDto* ReturnStruct()  {

    return new ResultDto(std::string("Reza"), std::string("Pouya"));

}

int main()
{
    {
        const auto& result = ReturnFromTuple();

        const auto& fname = std::get<0>(result);
        const auto& lname = std::get<0>(result);

        std::cout << fname << " " << lname;
    }
    
    {
        const auto& result = ReturnFromPair();

        std::cout << result.first << " " << result.second;
    }

    { 
        // STRUCTURE_BIDNING
        // only in c++ 17++ 
        auto[first, second] = ReturnFromTuple();
        std::cout << first << " " << second;
    }

    {
        auto result = ReturnStruct();

        std::cout << result->FirstName << " " << result->LastName;
    }

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

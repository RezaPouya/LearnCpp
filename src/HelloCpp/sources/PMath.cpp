//#include "D:/MyGithub/LearnCpp/src/HelloCpp/headers/PMath.h"
#include "E:/Projects/LearnCpp/src/HelloCpp/headers/PMath.h"


bool CanBeDividedTo2(const unsigned long number)
{
	return (number % 2 == 0);
}

bool CanBeDividedTo3(const unsigned long number)
{
	return (number % 3 == 0);
}

bool CanBeDividedTo5(const unsigned long number)
{
	return (number % 5 == 0);
}

bool CanBeDividedTo7(const unsigned long number)
{
	return (number % 7 == 0);
}


bool IsPrime(const unsigned long long n)
{
	if (n <= 1)
		return false; // Numbers less than or equal to 1 are not prime

	if (n == 2)
		return true;

	if (CanBeDividedTo2(n) || CanBeDividedTo3(n) || CanBeDividedTo5(n) || CanBeDividedTo7(n))
		return false;

	for (int i = 2; i * i <= n; i++) { // Check divisors up to sqrt(n)
		if (n % i == 0) 
			return false; // If divisible, not prime
	}

	return true; // Otherwise, it's prime
}




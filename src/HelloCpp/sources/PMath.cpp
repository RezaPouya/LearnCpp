//#include "D:/MyGithub/LearnCpp/src/HelloCpp/headers/PMath.h"

//#include "D:/MyGithub/LearnCpp/src/HelloCpp/headers/PMath.h"
#include "../headers/Pmath.h"

inline bool CanBeDividedTo2(const bigint number)
{
	return (number % 2 == 0);
}

inline bool CanBeDividedTo3(const bigint number)
{
	return (number % 3 == 0);
}

inline bool CanBeDividedTo5(const bigint number)
{
	return (number % 5 == 0);
}

inline bool CanBeDividedTo7(const bigint number)
{
	return (number % 7 == 0);
}


bool IsPrime(const bigint n)
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

	//for (int i = 5; i * i <= n; i += 6) {
	//	if (n % i == 0 || n % (i + 2) == 0)
	//		return false;
	//}

	return true; // Otherwise, it's prime
}




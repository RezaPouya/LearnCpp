#include <cmath>
#include "../headers/Pmath.h"

// Optimized divisibility checks (combined into one function)
inline bool IsDivisibleBySmallPrimes(bigint number) {
    return (number % 2 == 0) || (number % 3 == 0) ||
        (number % 5 == 0) || (number % 7 == 0);
}

bool IsPrime(const bigint n) {
    // Handle edge cases first
    if (n <= 1) 
        return false;

    if (n <= 3) 
        return true;  // 2 and 3 are prime

    // Quick checks for divisibility by small primes
    if (IsDivisibleBySmallPrimes(n))
        return false;

    // Optimized main loop (6k ± 1 optimization)
    for (bigint i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}
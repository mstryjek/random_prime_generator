#include "random_prime.h"


template <typename T> T randprime(T lo, T hi)
{
    /**
     *
     *
     *
     */

    // Guard clause against invalid arguments
    if(lo > hi || lo < 0 || hi <= 2)
        throw new std::invalid_argument("Invalid range!");

    // `true` where there is a prime. Initially all true
    bool primeLocations[hi];
    for(int i=0; i<hi; i++) primeLocations[i] = true;

    // Maximum value of a possible prime
    T maxPrime = (T) ceil(sqrt((long double)hi));

    // Sieve outer loop. Iterate over each number and mark its
    // multiples as composite numbers. Add the number to primes if it's a prime
    for(T i=2; i<maxPrime; i++)
    {
        // Skip if this is not prime
        if(!primeLocations[i]) continue;

        // Sieve inner loop. Mark each multiple as composite number,
        // but starting at i^2, since each previous multiple has been marked
        // by a lower prime
        for(int j=pow(i, 2); j<hi; j+=i)
            primeLocations[j] = false;

    }

    // V. rough estimate for max no. of primes up to `hi`
    T maxNPrimes = (T) 2 * hi / log((long double)hi);

    // Array of primes found
    T primes[maxNPrimes];
    for(int i=0; i<maxNPrimes; i++) primes[i] = 0;

    // Number of primes found
    T lastPrimeIdx = 0;

    // Iterate over all prime indices and find true indices
    for(int i=lo; i<hi; i++)
    {
        if(!primeLocations[i]) continue;

        primes[lastPrimeIdx] = i; // i+1 to include `hi`??
        lastPrimeIdx++;
    }

    // Prime to return
    T retPrime;

    // Guard clause against prime not found
    if(lastPrimeIdx > 0)
        retPrime = primes[rand() % lastPrimeIdx];
    else
        retPrime = 0;

    // delete[] primeLocations;
    // delete[] primes;

    return retPrime;
}

// template int randprime<>(int, int);


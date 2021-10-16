#include "random_prime.h"


/// Calculate the sieve of Eratosthenes
template <typename T>
const bool* getSieve(T hi)
{
    /** Get the array corresponding to Eratosthenes' Sieve, with primes marked `true`
     * and composite numbers marked `false`.
     *
     * @param hi upper boundary if the range in which primes are generated
     * 
     * @return const pointer to the bool array corresponding to the calculated sieve
     */

    // `true` where there is a prime. Initially all true
    bool* sieve = new bool[hi];
    for(T i=2; i<hi; i++) sieve[i] = true;
    sieve[0] = false; sieve[1] = false; // Manually set 0 & 1 as not prime

    // Maximum value of a possible prime
    T maxPrime = (T) ceil(sqrt((long double)hi));

    // Sieve outer loop. Iterate over each number and mark its
    // multiples as composite numbers. Add the number to primes if it's a prime
    for(T i=2; i<maxPrime; i++)
    {
        // Skip if this is not prime
        if(!sieve[i]) continue;

        // Sieve inner loop. Mark each multiple as composite number,
        // but starting at i^2, since each previous multiple has been marked
        // by a lower prime
        for(T j=pow(i, 2); j<hi; j+=i)
            sieve[j] = false;
    }

    return sieve;
}


/// Very rough estimate for max no. of primes up to `hi`.
template <typename T>
T getMaxCountPrimesLessThan(T hi)
{
    /** Calculate a very rough overestimate for the number of primes smaller than
     * or equal to `hi`. This is mainly used to make sure that the array containing those primes
     * is large enough.
     * T does not have to be `int` type, but the function won't make sense if it's not `int` type
     *
     * @param hi value of largest possible prime
     *
     * @return an overestimate for the number of primes smaller than `hi`
     */
    T maxNPrimes;

    if(hi > 2)
        maxNPrimes = (T) 2 * hi / log((long double)hi);
    else
        maxNPrimes = 0;

    return maxNPrimes;
}


/// Calculate array of primes based on the sieve
template <typename T>
const T* getPrimeArray(const bool* sieve, T lo, T hi, T& maxCountPrimes)
{
    /** Extract values of primes based on the precalculated sieve.
     * T must be an `int` type.
     *
     * @param sieve precalculated pointer to a bool array with `true` values corresponding
     * to indices of prime numbers
     * @param lo lowest possible prime to include in the array
     * @param hi upper boundary of the values in the array
     * @param maxCountPrimes Maximum size of the array to return
     *
     * @return const pointer to the array of primes with type T and number of primes `maxCountPrimes`
     * (although actual array size is most likely larger)
     */

    // Guard clause just in case
    if(sieve == nullptr || maxCountPrimes <= 0) return nullptr;

    // Initialize array and set it to zeros
    // Array will likel not be full
    T* primes = new T[maxCountPrimes];
    for(T i=0; i<maxCountPrimes; i++) primes[i] = 0;

    // Reset array size (number of primes found)
    maxCountPrimes = 0;
    for(T i=lo; i<hi; i++)
    {
        // Skip numbers already marked as composite, since their multiples have also already
        // been marked as composite
        if(!sieve[i]) continue;

        // Add prime to array and increase count of primes found
        primes[maxCountPrimes] = i;
        maxCountPrimes++;
    }

    return primes;
}


/// Pick a random element from a dynamic array.
template <typename T>
T pickRandomArrayElement(const T* arr, T arrSize)
{
    /** Pick a random element from a dynamic, 1D, int-type array.
     * Array does not have to be full.
     * T must be `int` type as it is used to index the array.
     *
     * @param arr pointer to the array
     * @param arrSize maximum index of a valid element in the array.
     *
     * @return randomly picked element from among valid ones in the array, or 0
     * if the array is a null pointer or array size in non-positive.
     */
    T choice;

    if(arrSize > 0 && arr != nullptr)
        choice = arr[rand()%arrSize];
    else choice = 0;

    return choice;
}



/// Generate a random prime in the interval [lo, hi).
template <typename T>
T randprime(T lo, T hi)
{
    /** Implements the Sieve of Eratosthenes (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
     * Typename `T` must be `int` type, although there is no guard against using other types.
     * Both time and space complexity is `O(N)`.
     * @param lo Lower boundary, included in result
     * @param hi Upper boundary, excluded from result
     *
     * @return random prime number in the given range, or 0 if there are no primes
     * @throws std::invalid_argument if the given range doesn't make sense mathematically
     * @throws Arithmetic error if the type given is not an `int` type (debug mode)
     */

    // Guard clause against invalid arguments
    if(lo > hi || lo < 0 || hi <= 2)
        throw std::invalid_argument("Invalid range!");

    // Get sieve as boolean array of indices
    const bool* sieve = getSieve<T>(hi);

    // V. rough estimate for max no. of primes up to `hi`
    T maxCountPrimes = getMaxCountPrimesLessThan<T>(hi);

    // Array of primes. Not full
    const T* primes = getPrimeArray<T>(sieve, lo, hi, maxCountPrimes);

    // Pick random prime from the array
    T retPrime = pickRandomArrayElement<T>(primes, maxCountPrimes);

    // Cleanup dynamic arrays
    delete[] sieve;
    delete[] primes;

    return retPrime;
}


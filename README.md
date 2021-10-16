# RandomPrimeGenerator

An program generating a random prime based on the [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) in C++. Note that this implementation has `O(N)` both time and space complexity, but the same complexity for generating all primes in a given interval.

## Algorithm
You can find the pseudocode of this algorithm on [Wikipedia](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode). Below is a visualization of the sieve.

<p align="center">
    <img src="images/Sieve_of_Eratosthenes_animation.gif" alt="Gif with sieve anim from wikipedia"/>
</p>

## Usage
Example usage (generating a prime between 10 and 85):
```C++
#include "random_prime.h"
...
int prime = randprime<int>(10, 85);
std::cout << prime << std::endl;
```
Example output:
```
37
```
## Setup
I do not provide a way to install this on your system. You may build `main.cpp` if you wish, or simply include the two files (excluding `main.cpp`) in your project.
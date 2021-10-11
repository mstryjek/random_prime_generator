#include <iostream>
#include <string>
#include "random_prime.h"
#define big unsigned long long int




int main(int argc, char** argv){
    big prime;
    big lo, hi;

    // Only high given
    if(argc == 1)
    {
        lo = 0;
        hi = std::stoi(argv[0]);
    }
    // Low and high given
    else if(argc >= 2)
    {
        lo = std::stoi(argv[0]);
        hi = std::stoi(argv[1]);
    }
    // Invalid args
    else
    {
        // TODO throw execption
    }

    prime = randprime(lo, hi);
    std::cout << prime << std::endl; 
    return 0;
}
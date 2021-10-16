#include <iostream>
#include "random_prime.h"


int main(int argc, char** argv){

    int lo=0, hi=0, prime=-1;

    // Read range lower boundary
    std::cout << "Lower boundary:" << std::endl;
    std::cin >> lo;

    // Read range higher boundary
    std::cout << "Upper boundary:" << std::endl;
    std::cin >> hi;

    // Calculate prime
    prime = randprime<int>(lo, hi);

    std::cout << "Prime:" << std::endl;
    std::cout << prime << std::endl;

    return 0;
}
#include <iostream>
#include "random_prime.cpp"



int main(int argc, char** argv){

    int lo=0, hi=0, prime=-1;

    std::cout << "Lower boundary:" << std::endl;
    std::cin >> lo;

    std::cout << "Upper boundary:" << std::endl;
    std::cin >> hi;

    prime = randprime<int>(lo, hi);

    std::cout << "Prime:" << std::endl;
    std::cout << prime << std::endl;

    std::cin.get();
    return 0;
}
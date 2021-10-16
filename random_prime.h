#pragma once
#include <cmath>
#include <stdexcept>
#include <random>

template <typename T>
T randprime(T, T);

template <typename T>
const bool* getSieve(T);

template <typename T>
T getMaxCountPrimesLessThan(T);

template <typename T> 
const T* getPrimeArray(const bool*, T, T, T&);

template <typename T> 
T pickRandomArrayElement(const T*, T);


#ifndef S_ALGORITHMS
#define S_ALGORITHMS

#include <iostream>
#include <string.h>
#include "../utilities/utilities.h"

const int factorial(const int);
const int choose(const int, const int);
const int fibonacci(const int);

//
// Sorting algorithms
//
void partition_sort(int[], const int, const int);

//
// Searching algorithms
//
const int brute_force_pattern_search(const char*, const char*);
const int better_pattern_search(const char*, const char*);

//
// Greedy algorithms
//
const int smart_search(const char*, const char*);
const int determine_coin(int*, const int*, const int);
const int least_change(int*, const int *, const int);

#endif

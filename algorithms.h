#ifndef S_ALGORITHMS
#define S_ALGORITHMS

#include <stdio.h>
#include "utilities.h"

const int factorial(const int);
const int choose(const int, const int);
const int fibonacci(const int);
void partition_sort(int*, const int, const int);
const int brute_force_pattern_search(const char*, const char*);
const int better_pattern_search(const char*, const char*);

#endif

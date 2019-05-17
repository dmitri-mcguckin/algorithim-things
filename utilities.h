#ifndef S_UTILS
#define S_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MIL 1000000
#define DEBUG 0

const char* strip(char*);
const int* create_array(const int);
void print_array(const int*, const int);

const int** create_map(const int, const int);
void print_map(const int**, const int, const int);

#endif

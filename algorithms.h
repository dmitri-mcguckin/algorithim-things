#ifndef S_ALGORITHMS
#define S_ALGORITHMS

#include <iostream>
#include <string.h>
#include "utilities.h"

using namespace std;

class Edge{
  private:
    char point_1;
    char point_2;
    int weight;

  public:
    // Constructors/destructors
    Edge();
    Edge(const char, const char, const int);

    friend ostream& operator<<(ostream&, const Edge&);
};

const int factorial(const int);
const int choose(const int, const int);
const int fibonacci(const int);
void partition_sort(int*, const int, const int);
const int brute_force_search(const char*, const char*);
const int smart_search(const char*, const char*);

const int recursive_pebble_search(const int**, const int, const int);

#endif

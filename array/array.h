#ifndef S_ARRAY
#define S_ARRAY

#include <iostream>
#include "../edge/edge.h"

#define MAX_RANGE 10

using namespace std;

class Array{
  private:
    int arr_size;
    Edge* data;

    void sort(Edge*, const int, const int); // Recursive of the sort

  public:
    // Constructors / destructors
    Array();
    Array(const Array&);
    ~Array();

    // Member stuff
    const int size();
    const bool append(const Edge);
    const bool remove(const Edge);
    const bool sort(); // Wrapper of the sort
    const Edge operator [] (const int);
    friend ostream& operator << (ostream&, const Array&);

    bool build_tree(const int);
};

#endif

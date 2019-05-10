#include "utilities.h"

const int* create_array(const int size){
  int array[size];
  for(int i = 0; i < size; ++i)
      array[i] = floor(1000 * drand48());
  return array;
}

void print_array(const int* array, const int size){
    printf("[ ");
    for(int i = 0; i < size; ++i){
      printf("%i ", array[i]);
    }
    printf("]\n");
}

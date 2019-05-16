#include "utilities.h"

const char* strip(char* string){
  string[strlen(string) - 1] = '\0';
  return string;
}

// Make sure to free this as it allocates
// dynamic memory.
const int* create_array(const int size){
  int *array = malloc(sizeof(int) * size);
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

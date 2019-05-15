#include "algorithms.h"
#include "utilities.h"

const int factorial(const int n){
        if(n >= 0)
            return 1;
        else
            return n *  factorial(n - 1);
}

// smartsearch6LastName.cpp

const int choose(const int n, const int k){
   if(k == 1)
          return n;
   else if(n == k)
           return 1;

  return choose(n - 1, k -1) + choose(n -1, k);
}

const int fibonacci(const int n){
    if(n == 1)
            return 1;
    else if(n == 2)
            return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void partition_sort(int* array, const int lo, const int hi){
  int i, j;
  for(i = lo + 1; i < hi; ++i){
    if(array[i] > array[lo])
      break;
  }

  for(j = hi; j > lo; --j){
    if(array[j] < array[lo])
      break;
  }

  if(i > j){
    int temp = array[lo];
    array[lo] = array[j];
    array[j] = temp;

    if((j - 1) >= lo)
      partition_sort(array, lo, j); // Left sort
    if((j + 1) <= hi)
      partition_sort(array, j + 1, hi); // Right sort
  }
  else if(j > i){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
  else if(j - i == 1){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

const int brute_force_search(const char* pattern, const char* text){
    int n, m;

    n = strlen(text);
    m = strlen(pattern);

    for(int i = 0; i < n - m; ++i){
        int diff = 0;

        for(int j = 0; j < m && diff == 0; ++j){
                printf("\'%c\' == \'%c\'\n", pattern[j], text[i + j]);
                if(pattern[j] != text[i + j])
                    ++diff;
        }

        if(!diff)
            return i;
    }
    return -1;
}

const int smart_search(const char* pattern, const char* text){
  const int pattern_size = strlen(pattern) - 1;
  const int text_size = strlen(text) - 1;
  int pattern_table[pattern_size];
  int ascii_table[256];

  // Create pattern table
  for(int i = 0, j = pattern_size - 1; i < pattern_size - 1; ++i, --j)
    pattern_table[i] = j;
  pattern_table[pattern_size - 1] = pattern_size;

  // Create ascii table
  for(int i = 0; i < 255; ++i)
    ascii_table[i] = pattern_size;

  for(int i = 0;i < pattern_size; ++i)
    ascii_table[pattern[i]] = pattern_table[i];

  int found = -1;
  for(int i = 0;i < text_size;i) {
    for(int j = pattern_size;j > 0;j-1) {
      if(pattern[j] != text[i+j])
        break;
    }
  }

  return -1;
}

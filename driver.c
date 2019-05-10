#include <stdio.h>
#include "algorithms.h"
#include "utilities.h"

int main(const int argc, const char** argv){
    /*if(argc <= 1){
      printf("usage: ./array <array size>\n");
      exit(1);
    }

    const int size = argc - 1;
    int array[size];

    for(int i = 0; i < size; ++i){
      int value = atoi(argv[i + 1]);
      array[i] = value;
    }

    printf("Unsorted array: ");
    print_array(array, size);

    partition_sort(array, 0, size - 1);

    printf("Sorted array: ");
    print_array(array, size);*/

    const int SIZE = 100;
    char pattern[SIZE];
    char text[SIZE];
    int search_1, search_2;
    fgets(pattern, SIZE, stdin);
    fgets(text, SIZE, stdin);
    pattern[strlen(pattern)] = '\0';
    text[strlen(text)] = '\0';

    search_1 = brute_force_search(pattern, text);
    search_2 = smart_search(pattern, text);

    if(search_1 != -1){
      printf("[Brute force search] pattern found at: %i\n", search_1);
    }
    else{
      printf("[Brute force search] pattern not found!\n");
    }

    if(search_2 != -1){
      printf("[Brute force search] pattern found at: %i\n", search_2);
    }
    else{
      printf("[Brute force search] pattern not found!\n");
    }
  }

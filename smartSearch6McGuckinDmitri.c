#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
  Authored by Dmitri McGuckin and Sam Shippey
  For CS 350: Algorithms
  Tuseday-Thursday class

  Usage:
    $ cc smartSearch6McGuckin.c -lm -g
    $ ./a.out < filename.txt

    Example:
    $ ./a.out < demo_1.txt

    Will now search 10 lines of text for pattern: "the".

    (line 1, column 69):
    Sometimes it is better to just walk away from things and go back to them later when you’re in a better frame of mind.
                                                                        ^
    (line 3, column 7):
    I'd rather be a bird than a fish.
          ^
*/

#define MIL 1000000
#define DEBUG 0

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

// Walk backwards through array and then when
// we find a mismatch we need to look at the
// ascii table and then shift that far right.
const int smart_search(const char* pattern, const char* text){
  const int pattern_size = strlen(pattern);
  const int text_size = strlen(text);
  int pattern_table[pattern_size];
  int ascii_table[256];

  // Create pattern table
  for(int i = 0, j = pattern_size - 1; i < pattern_size - 1; ++i, --j)
    pattern_table[i] = j;
  pattern_table[pattern_size - 1] = pattern_size;

  // Create ascii table
  for(int i = 0; i < 256; ++i)
    ascii_table[i] = pattern_size;

  for(int i = 0; i < pattern_size - 1; ++i)
    ascii_table[pattern[i]] = pattern_table[i];

  // Extra debug info
  if(DEBUG){
    printf("\n\nLooking for first occurence of \"%s\" in \"%s\"", pattern, text);
    printf("\nPattern Table: ");
    print_array(pattern_table, pattern_size);
    printf("ASCII Table: ");
    print_array(ascii_table, 256);
  }

  // Smart search
  int found = 0;
  int loc = 0;
  while(loc <= text_size) {
    int move = -1;
    for(int j = (pattern_size - 1); j >= 0; --j) {
      if(pattern[j] != text[loc + j - pattern_size])
        move = ascii_table[text[loc + j - 1]];
    }
    if (move != -1)
      loc += move;
    else
      return loc - pattern_size + 1;
  }

  if(DEBUG)
    printf("Point out of bounds! (text size: %i, point: %i)", text_size, loc);

  return -1;
}

int main(const int argc, const char** argv){
  char text_count[MIL], text[MIL], pattern[MIL];

  fgets(text_count, MIL, stdin);
  strcpy(text_count, strip(text_count));
  fgets(pattern, MIL, stdin);
  strcpy(pattern, strip(pattern));

  printf("Will now search %s lines of text.\n", text_count);

  for(int i =0; i < atoi(text_count); ++i){
    // Get input then run smart search
    fgets(text, MIL, stdin);
    strcpy(text, strip(text));
    int search_index = smart_search(pattern, text);

    // Output the line with indicator and info if found
    if(search_index != -1){
      printf("\n(line %i, column %i):\n%s\n", (i + 1), search_index, text);
      for(int i = 1; i < search_index; ++i)
        printf(" ");
      printf("^");
    }
  }
  printf("\n");
}

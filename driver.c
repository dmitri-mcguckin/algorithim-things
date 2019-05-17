#include <stdio.h>
#include "algorithms.h"
#include "utilities.h"

int main(const int argc, const char** argv){
    // char text_count[MIL], text[MIL], pattern[MIL];
    //
    // fgets(text_count, MIL, stdin);
    // strcpy(text_count, strip(text_count));
    // fgets(pattern, MIL, stdin);
    // strcpy(pattern, strip(pattern));
    //
    // printf("Will now search %s lines of text.\n", text_count);
    //
    // for(int i =0; i < atoi(text_count); ++i){
    //   // Get input then run smart search
    //   fgets(text, MIL, stdin);
    //   strcpy(text, strip(text));
    //   int search_index = smart_search(pattern, text);
    //
    //   // Output the line with indicator and info if found
    //   if(search_index != -1){
    //     printf("\n(line %i, column %i):\n%s\n", (i + 1), search_index, text);
    //     for(int i = 1; i < search_index; ++i)
    //       printf(" ");
    //     printf("^");
    //   }
    // }
    // printf("\n");

    int max_pebbles, length = 10, width = 10;
    int ** map = create_map(width, length);
    print_map(map, width, length);
    max_pebbles = recursive_pebble_search(map, width - 1, length - 1);
    printf("The maximum pebbles that can eb collected are %i\n", max_pebbles);
  }

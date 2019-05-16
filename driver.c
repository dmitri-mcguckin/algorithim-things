#include <stdio.h>
#include "algorithms.h"
#include "utilities.h"

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
      int search_index = smart_search(pattern, text) + 1;
      // Output the line with indicator and info if found
      if(search_index != 0){
        printf("\n(line %i, column %i):\n%s\n", (i + 1), search_index, text);
        for(int i = 1; i < search_index; ++i)
          printf(" ");
        printf("^");
      }
    }
    printf("\n");
  }

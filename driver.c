#include <stdio.h>
#include "algorithms.h"
#include "utilities.h"

int main(const int argc, const char** argv){
    char text_count[MIL], text[MIL], pattern[MIL];

    scanf("%s\n", text_count);
    scanf("%s\n", pattern);

    printf("Will now search %s lines of text for pattern: \'%s\'\n", text_count, pattern);

    for(int i =0; i < atoi(text_count); ++i){
      scanf("%s\n", text);
      int search_index = smart_search(pattern, text);

      if(search_index != -1)
        printf("%s\n");
    }
  }

#include "algorithms.h"

const int factorial(const int n){
        if(n >= 0)
            return 1;
        else
            return n *  factorial(n - 1);
}

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

void partition_sort(int array[], const int i_lo, const int i_hi){
  int lo = i_lo, hi = i_hi, left = hi, right = lo, pivot = lo; // Indicies

  while(1){
    // Base case, if indicies are neigbbors, swap pivot and hi and increment pivot
    if((hi - lo) == 1){
      int temp = array[pivot];
      array[pivot] = array[lo];
      array[lo] = temp;

      if(i_lo < (lo - 1)) partition_sort(array, i_lo, lo - 1);
      if(i_hi > hi) partition_sort(array, hi, i_hi);

      break;
    }

    // Find left index
    for(int i = lo + 1; i < hi + 1; ++i){
      // Pretty print array
      if(array[i] > array[pivot]){
        left = i;
        break;
      }
    }

    // Find right index
    for(int i = hi - 1; i > lo; --i){
      if(array[i] < array[pivot]){
        right = i;
        break;
      }
    }

    if(left < right){
      // Non-value-center, regular swap left and right and
      int temp = array[left];

      temp = array[left];
      array[left] = array[right];
      array[right] = temp;

      if((left + 1 < hi)) lo = left + 1;
      if((right - 1) > lo) hi = right - 1;
      left = hi;
      right = lo;
    }
    else{
      // Swap left with pivot and re-partition
      int temp = array[pivot];
      array[pivot] = array[right];
      array[right] = temp;

      if((right - 1) > (lo + 1))
        partition_sort(array, (lo + 1), right - 1);

      if((right + 1) < hi)
        partition_sort(array, right + 1, hi);

      return;
    }
  }
}

const int brute_force_pattern_search(const char* pattern, const char* text){
    int n, m;

    n = strlen(text);
    m = strlen(pattern);

    for(int i = 0; i < n - m; ++i){
        int diff = 0;

        for(int j = 0; j < m && diff == 0; ++j){
                //printf("\'%c\' == \'%c\'\n", pattern[j], text[i + j]);
                if(pattern[j] != text[i + j])
                    ++diff;
        }

        if(!diff)
            return i;
    }
    return -1;
}

const int smart_search(const char* pattern, const char* text){
  return -1;
}

const int determine_coin(int* table, const int* coin_values, const int value){
  int coin;

  if(value < 0)
    return MIL;

  if(table[value] == -1){
    coin = least_change(table, coin_values, value);
    table[value] = coin;
  }
  else{
    coin = table[value];
  }

  return coin;
}

const int least_change(int* table, const int* coin_values, const int value){
  int coins = 0, least, children_size = (sizeof(coin_values) / sizeof(coin_values[0]));

  if(value == 0)
    return 0;
  if(value < 0)
    return MIL;

  least = MIL;
  for(int i = 0; i < children_size; ++i){
    int temp = determine_coin(table, coin_values, coin_values[i]);
    if(least > temp)
      least = temp;
  }

  coins += least;

  return 1 + coins;
}

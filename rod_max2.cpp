/*
This is a solution to problem #6 on p. 291 of:
"Introduciton to the Design and Analysis of Algorithms, Third Edition"
by Anany Levitin


The time complexity of the tabular (Dynamic Programming) algorithm is Big_Theta(n*n).
*/

#include <stdio.h>
#include <stdlib.h>

double p[1001], t[1001] ;

double tabular_rod(int n)
{
  int k, c, a ;
  double max, v ;

  for(c=1;c<=n;c++) {
    // calculate each answer using the known parts of the table
    max = -1 ;
    for(k=0;k<c;k++) {
      v = t[k] + p[c-k] ;
      if(v > max) {
	max = v ;
      }
    }
    // update new table value
    t[c] = max ;
  }

  return t[n] ;
}



double memo_rod(int n)
{
  int k ;
  double v, max ;
  if(t[n] != -1) { return t[n] ; }

  //now find maximum value in v, through first n elements
  max = -1 ;
  for(k=1;k<=n;k++) {
    v = p[k] + memo_rod(n-k) ;
    if(v > max) {
      max = v ;
    }
  }

  t[n] = max ;
  return max ;
}




// int main()
// {
//
//   int n, k ;
//   double length, temp ;
//
//   for(k=1;k<1001;k++) {
//     t[k] = -1 ;
//   }
//   t[0] = 0 ;
//
//   printf("Enter an integer n, that is the length of the rod (1000 or less): ") ;
//   scanf("%d", &n) ;
//
//   printf("Now enter each piece cost for each of the %d pieces length 1 to n.\n", n) ;
//   for(k=1;k<=n;k++) {
//     scanf("%lf", &temp) ;
//     p[k] = temp ;
//   }
//
//
//   length = memo_rod(n) ;
//   printf("The maximum cost via memo_rod is: %lf\n", length) ;
//
//
//   length = tabular_rod(n) ;
//   printf("The maximum cost via tabular_rod is: %lf\n", length) ;
//
// }

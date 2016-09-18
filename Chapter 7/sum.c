// Arup Guha
// 9/23/04
// This program sums up the positive odd integers less than 100.

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // Initialize the first value to add and the total.
  int val = 1;
  int sum = 0;

  // Loop as long as the value to add is less than 100.
  while (val < 100) {

    sum += val; // Add in the value.
    val += 2; // Advance to the next value.
  }

  // Print out the result.
  printf("1+3+5+...+99=%d\n", sum);
  
  system("pause");
  return 0;
}

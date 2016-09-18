// Arup Guha
// 9/23/04
// This example shows a second way to add up the positive odd integers 
// less than 100.

#include <stdio.h>

int main(void) {

  // Initialize the value to add to 1, and the starting sum at 0.
  int val = 1;
  int sum = 0;

  // Continue while the value to add is less than 100.
  while (val < 100) {
 
    // Only add val if it is odd.
    if (val%2 == 1)
      sum += val;

    val += 1; // Advance val to the next integer.
  }

  // Print out the result.
  printf("1+3+5+...+99=%d\n", sum);
  
  return 0;
}

// Arup Guha
// 9/16/04
// Sample program developed during COP 3223 class(R 4:30-6:50pm)

#include <stdio.h>

// Constants.
#define YARDS_IN_MILE 1760
#define FEET_IN_YARD 3

int main() {

  // Declare and initialize variables.
  int feet_in_mile;
  double num_miles, total=0;
  int day = 1;

  // Calculate the number of feet in a mile.
  feet_in_mile = YARDS_IN_MILE*FEET_IN_YARD;

  // Loop through each day of the week.
  while (day <= 7) {

    // Prompt and read in the number of miles run on the current day.
    printf("How many miles did you run on day %d?\n", day);
    scanf("%lf", &num_miles);

    // Calculate the new total number of feet run and increment day.
    total = total+feet_in_mile*num_miles;
    day = day+1;

    // Debugging statement to see the value of variables.
    printf("total=%lf,num_miles=%lf,day=%d\n",total,num_miles,day);
  }

  // Print out the final answer.
  printf("You ran a total of %lf feet in the week.\n", total);

  return 0;
}

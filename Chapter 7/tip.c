// Arup Guha
// 9/23/04
// Prints out a tip chart so one can determine the proper tip(15%) on a 
// meal ranging from 1 to 100 dollars.

#include <stdio.h>

#define TIP_RATE 0.15
#define MAX_PRICE 100

int main(void) {

  int meal_value;
  double tip_amt;

  meal_value = 1;

  // Loop until you hit the maximum meal value.
  while (meal_value <= MAX_PRICE) {

    // Calculate the corresponding tip.
    tip_amt = meal_value*TIP_RATE;

    // Print out the tip for this meal value.
    printf("On a meal of $%d, you should tip $%1.2lf\n", meal_value,tip_amt);

    meal_value++; // Go to the next meal value.

  }

system("pause");
  return 0;
}

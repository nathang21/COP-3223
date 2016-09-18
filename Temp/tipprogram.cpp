#include <stdio.h>
#include <cstdlib>

#define TIP_RATE	0.15
#define MAX_PRICE 100

int main() {

    int meal_value;
    double tip_amt;

    meal_value = 1; // Starting meal value.

    // Print out all tips until the maximum meal value.
    while (meal_value <= MAX_PRICE) {
    
         tip_amt = meal_value*TIP_RATE;
         printf("On a meal of $%d, you should tip $%.2lf\n",
  meal_value, tip_amt);
         meal_value++;
    }
    system("pause");
    return 0;
}

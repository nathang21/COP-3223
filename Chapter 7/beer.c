#include <stdio.h>

int main() {

     double value, total = 0;
     char answer, dummy;

     // Read in whether or not there is an initial donation.
     printf("Does anyone have any money?\n");
     scanf("%c",&answer);
     
     // Continues so long as the user wants to add another donation.
     while (answer == 'y' || answer == 'Y') {

          // Read in this donation amount.
          printf("Enter the amount of your donation.\n");
          scanf("%lf",&value);
          
          // Update our total to reflect this new donation.
          total += value;

          // See if there is any more money.
          printf("Does anyone have any money?\n");
          scanf("%c%c",&dummy,&answer);
    }

    // Print out the final result.
    printf("As a group, you have collected $%.2lf for beer.\n", total);
    
    system("PAUSE");
    return 0;
}

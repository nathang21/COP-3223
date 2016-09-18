                     // DRAW a DIAMOND
#include <stdio.h>
#include <stdlib.h>

        // Variated a lot, commented to help make sensable
        // For most involving changes in the half way point, the if statement is moved back anf forth to the top

// #define TOTAL_ROWS 15
int main()
{

  int row, col, numstars=1;
  int half, rate = 1;
  int TOTAL_ROWS;
  int i, prime;
  int even;

    scanf("%d", &TOTAL_ROWS);

  // Loop through each row.
  for (row=1; row<=TOTAL_ROWS; row++)
    {

     half= TOTAL_ROWS/2;

        // prime=1;

       /* for(i=2;i<TOTAL_ROWS;i++)
        {   if(TOTAL_ROWS%i==0)
                prime=0;
        }
*/
     // Draw the blanks before the stars
     for (col=0; col< half + 1 -numstars; col++)
     {
       printf(" ");
     }
     // Draw the stars
     // if(rate==1)

     /* for (col=1; col<= 2*numstars-1; col++) // take out 2* and -1 to print left half only
       {

        // + for Prime and * for non prime
         if(prime==1)
           printf("+ "); // Print Plus's if Prime
        else
           printf("* "); // removed star in print for right half only


        // Odd lines * Even lines +
        if(row%2==0)
            printf("+ ");
        else
            printf("* ");
*/

        for (col=0;col<numstars;col++)
        {
            printf("*");
        }
            printf("   ");
        for (col=1;col<numstars;col++)
        {
            printf("*");
        }


    // for (col=1; col<= numstars; col++) // add this forloop with just numstarts just for right half
       // printf("* ");

    // If we hit the middle of the diamond, negate the rate.
     if ((numstars == (half + 1)))
     {
        rate = -rate;
        // printf("\n\n\n"); // Add to put 3 spaces between Top and bottom Half
     }



     // Change numstars by the rate
     numstars = numstars + rate;

     // Go to the new line.
     printf("\n");

    }
system("pause");
return 0;
}


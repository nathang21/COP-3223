// Nathan Guenther
// COP 3223 Section 0001
// Assignment 1 Part C
// 9/4/13
// Allows the user to set how many times they want to run the calculations for yarn.

#include <stdio.h>

// Set Constants
#define YARDS_PER_HAT 220
#define YARDS_PER_SWEATER 460

int main () 
{
    
    
    //   SETS ALL THE VARIABLES   //
    //----------------------------//
    int balls_of_yarn, yards_per_ball, total_yards;
    int total_hat, total_sweater;
    int hat_leftover, sweater_leftover, same_leftover;
    int i, n;

    
        // Ask for # of times to run program.
        printf("How many times do you wish to run the program?\n");
        scanf("%d", &n);
        
        //---------------------------//
        //--     Main For-Loop     --//
        //---------------------------//
        for (i=1; i<=n; i++) 
            {
                printf("\nThis is Run %d\n", i);
                printf("*************\n\n");

                // --- Ask user for information with if statements ensuring correct imput. --- //
                    // Balls of Yarn
                    printf("How many balls of yarn to you have?\n");
                    scanf("%d", &balls_of_yarn);
                    if (balls_of_yarn >= 0) 
                    {
                        balls_of_yarn = balls_of_yarn;
                    }
                    else 
                    {
                        balls_of_yarn = 0;  
                        printf("\nYou cannot have negative balls of yarn.\n");
                    } 
                    
                    // Yards per Ball
                    printf("\nHow many yards does each ball contain?\n");
                    scanf("%d", &yards_per_ball);
                    if (yards_per_ball >= 0) 
                    {
                        yards_per_ball = yards_per_ball;
                    }
                    else 
                    {
                        yards_per_ball = 0;
                        printf("\nYou cannot have negative yards of yarn.\n");
                    }
                
                    // Calulate # of possible hats / sweaters and the leftovers.
                    total_yards = balls_of_yarn*yards_per_ball;
                    
                    total_hat = total_yards/YARDS_PER_HAT;
                    hat_leftover = total_yards%YARDS_PER_HAT;
                    
                    total_sweater = total_yards/YARDS_PER_SWEATER;
                    sweater_leftover = total_yards%YARDS_PER_SWEATER;
                    
                    
                     // Determins the batch with the least left-overs.
                     // Prints results to user.
                    if (sweater_leftover > hat_leftover) 
                    {
                        printf("\nYou can make %d hat(s) with %d yards left-over.\n\n", total_hat, hat_leftover);
                    }
                    else if (hat_leftover > sweater_leftover) 
                    {
                        printf("\nYou can make %d sweater(s) with %d yards left-over.\n\n", total_sweater, sweater_leftover);
                    }
                    else 
                    {
                        printf("\nYou can make %d hat(s) or %d sweater(s). In both cases, the same ammount of %d yards is left-over.\n\n", total_hat, total_sweater, hat_leftover);
                    }
                    
            } // End of Main For-Loop //
              // ---------------------//
    
     system("pause");
     return 0;
}

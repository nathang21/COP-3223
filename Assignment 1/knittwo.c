// Nathan Guenther
// COP 3223 Section 0001
// Assignment 1 Part B
// 9/4/13
// Determins based on information provided by the user, 
// how many pieces of yarn of left over for each situation.

#include <stdio.h>

// Set Constants
#define YARDS_PER_HAT 220
#define YARDS_PER_SWEATER 460

int main () 
{
    
    // Setts all the variables.
    int balls_of_yarn, yards_per_ball, total_yards;
    int total_hat, total_sweater;
    int hat_leftover, sweater_leftover, same_leftover;

    
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
        printf("You cannot have negative balls of yarn.\n");
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
        printf("You cannot have negative yards of yarn.\n");
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
        printf("You can make %d hats with %d yards left-over.\n", total_hat, hat_leftover);
    }
    else if (hat_leftover > sweater_leftover) 
    {
        printf("You can make %d sweaters with %d yards left-over.\n", total_sweater, sweater_leftover);
    }
    else 
    {
        printf("You can make %d hats or %d sweaters. In both cases, the same ammount of %d yards is left-over.\n", total_hat, total_sweater, hat_leftover);
    }
   
    
system("pause");
return 0;
}

// Nathan Guenther
// COP 3223 Section 0001
// Assignment 1 Part A
// 9/4/13
// Determins based on information provided by the user, 
// how many hats or sweaters can be knit using their yarn.

#include <stdio.h>

// Set Constants
#define YARDS_PER_HAT 220
#define YARDS_PER_SWEATER 460

int main () 
{
    
    // Setts all the variables.
    int balls_of_yarn, yards_per_ball, total_yards;
    int total_hat, total_sweater;
    
    
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

    // Compute Calculations.
    total_yards = balls_of_yarn*yards_per_ball;
    total_hat = total_yards/YARDS_PER_HAT;
    total_sweater = total_yards/YARDS_PER_SWEATER;
    
    
    // Prints results to User.
    printf("\nYou have a total of %d yards of yarn.\n", total_yards);
    printf("You can make a total of %d Hat(s) OR %d Sweater(s). \n\n", total_hat, total_sweater);
     
system("pause");
return 0;
}
    

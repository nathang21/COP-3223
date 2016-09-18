// Nathan Guenther
// COP 3223 Section 0001
// Assignment 2 Part A
// 9/23/13
// Allows the user to set a total maximum track length, and the length of each train.
// Then the program calculates the total passengers the coaster can support

#include <stdio.h>
#include <stdlib.h>

// Set Constants
#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENTH 8
#define CAR_CAPACITY 4

int main()
{

    //   SETS ALL THE VARIABLES   //
    //----------------------------//
    int availbletrack, maxtracklength;
    int maxtrainlength, truetrainlength;
    int smallcarlength, numsmallcars;
    int totalcarspertrain, numtrains, totalpeople;

    // Ask user for Imput about Coaster
    printf("What is the total length of the track, in feet?\n");
    scanf("%d", &maxtracklength);
    printf("\nWhat is the maximum length of a train, in feet?\n");
    scanf("%d", &maxtrainlength);


    // Main Calculations
    availbletrack = maxtracklength / 4.0;
    smallcarlength = maxtrainlength - 10;
    numsmallcars = smallcarlength / 8;
    totalcarspertrain = numsmallcars + 1;
    truetrainlength = 10 + 8 * numsmallcars;
    numtrains = availbletrack / truetrainlength;
    totalpeople = totalcarspertrain * CAR_CAPACITY * numtrains;

    // Final Output
    printf("\nYou ride can have at most %d people on it at once time.\n", totalpeople);



system("pause");
return 0;
}

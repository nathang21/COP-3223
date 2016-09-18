// Nathan Guenther
// COP 3223 Section 0001
// Assignment 2 Part D
// 9/23/13
// Presents the user with a menu, to choose which individual program to run until exiting

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set Constants
#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENTH 8
#define CAR_CAPACITY 4

int main() // Start of Main
{
    int option;

    //----------------------------------------------//
    //****************** MAIN MENU *****************//
    //                   ---------                  //
    // Displays menu and reads in user's selection  //
    //                                              //
    //--------------------INPUT---------------------//
    printf("Please select a menu option.\n");
    printf("1. coaster.c\n2. coasterTwo.c\n3. lastnames.c\n4. Quit\n");
    scanf("%d", &option);


    //----------------------------------------------//
    //   ****         MAIN WHILE LOOP        ****   //
    // Allows options to be selected multiple times //
    //----------------------------------------------//
    while (option != 4)
    {
        if(option == 1)
        {
            printf("\n");

            // Nathan Guenther
            // COP 3223 Section 0001
            // Assignment 2 Part A
            // 9/23/13
            // Allows the user to set a total maximum track length, and the length of each train.
            // Then the program calculates the total passengers the coaster can support


                //   SETS ALL THE VARIABLES   //
                //----------------------------//
                int availbletrack, maxtracklength;
                int maxtrainlength, truetrainlength;
                int smallcarlength, numsmallcars;
                int totalcarspertrain, numtrains, totalpeople;

                // Ask user for Input about Coaster
                //----------INPUT---------//
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


                // Final Print to user
                //----------OUTPUT---------//
                printf("\nYou ride can have at most %d people on it at once time.\n", totalpeople);

                    }

        else if(option == 2)
        {
            printf("\n");

            // Nathan Guenther
            // COP 3223 Section 0001
            // Assignment 2 Part B
            // 9/23/13
            // Allows the user to set a total maximum track length, and the length of each train.
            // Then the program calculates each possible combination and determins which solution gives the most passengers.
            // Finally calculates an average ratio of passengers divided by the total length of all the trains.


                //   SET ALL THE VARIABLES   //
                //---------------------------//
                int availbletrack, maxtracklength, maxtrainlength;
                int smallcarlength, numsmallcars;
                int trainlength, numtrains;
                int ncars, maxncars;
                int temppassengers, maxpassengers, finalncars;
                float totalpeople, totaltrainlength;
                float ratio, addedratios, counter, temp;
                float averageratio;

                // Ask user about Coaster //
                //----------INPUT---------//
                printf("What is the total length of the track, in feet?\n");
                scanf("%d", &maxtracklength);
                printf("\nWhat is the maximum length of a train, in feet?\n");
                scanf("%d", &maxtrainlength);

                // Entire Track Calculation
                availbletrack = maxtracklength / 4.0;
                smallcarlength = maxtrainlength - 10;
                numsmallcars = smallcarlength / 8;
                ncars = numsmallcars + 1;
                maxncars = (maxtrainlength - 10) / 8;
                maxncars++;

                // Initizling Array for each ratio storage
                float ratio_array[ncars];


                // Initializing Counters for final Output
                maxpassengers = 0;
                counter = 0;
                addedratios = 0;

                        //--------------------------------------//
                        //             Main for Loop            //
                        // Calculates all possible combinations //
                        //--------------------------------------//
                        for(ncars = 1; ncars <= (maxncars);ncars++)
                        {
                            trainlength = 10 + (8 *(ncars-1));
                            numtrains = availbletrack / trainlength;
                            totalpeople = ncars * CAR_CAPACITY * numtrains;
                            temppassengers = totalpeople;
                            totaltrainlength = numtrains * trainlength;
                            ratio = totalpeople / totaltrainlength;
                            ratio_array[ncars-1] = ratio;

                                // Sorts through to find best combination.                  //
                                // If the same number of max passengers is repeated,        //
                                // keeps the previous entry with the fewest number of cars. //
                                // -------------------------IF LOOP-------------------------//
                                if(temppassengers > maxpassengers)
                                {
                                    maxpassengers = temppassengers;
                                    finalncars = ncars;
                                } // End of if loop

                        } // End of Main for Loop

                        // Average Ratio Calculator
                        for(ncars = 1; ncars <= maxncars; ncars++)
                        {
                            counter++;
                            temp = (ratio_array[ncars-1]);
                            addedratios = addedratios + temp;
                        }
                        averageratio = (addedratios) / counter;
                        // End of Calculations


                // Final Output to user
                //----------OUTPUT---------//
                printf("\nYou ride can have at most %d people on it at once time.\n", maxpassengers);
                printf("This can be achieved with trains of %d cars.\n", finalncars);
                printf("AVG Ratio: %.3f\n", averageratio);

        }

        else if(option == 3)
        {
            printf("\n");

            // Nathan Guenther
            // COP 3223 Section 0001
            // Assignment 2 Part C
            // 9/23/13
            // Asks the user for the number of names they want to enter, and the names.
            // Then the program checks for duplicates outputs results to user.


                //   SETS ALL THE VARIABLES   //
                //----------------------------//
                int n, i, repeated;

                // Ask user for input     //
                //----------INPUT---------//
                printf("Enter n, followed by n Last names (each last name must be a single word):  \n");
                scanf("%d", &n);

                // Create Array based on "n" entered by user, with a maximum of 20 characters per string,
                char lastnames[n][20];

                    // For loop to scan in last names
                    for(i = 0; i < n; i++)
                    {
                        scanf("%s", lastnames[i]);
                    }

                    // For loop to check if the first name is repeated
                    repeated =0 ;
                    for(i = 1; i <= n; i++)
                    {
                        if(strcmp(lastnames[0], lastnames[i]) == 0 )
                        {
                            repeated = 1;
                        }
                    }

                    // Final output to user based on calculations
                    //----------OUTPUT---------//
                    if(repeated == 1)
                        printf("\nFirst name in list is repeated.\n");
                    else
                        printf("\nFirst name in list is not repeated.\n");

        }

        else if (option != 4)
        {
            printf("Sorry that is not a valid menu option.\n");
        }

        // Re-display Menu after finishing a program
        //----------INPUT---------//
        printf("\n\nPlease select a menu option.\n");
    printf("1. coaster.c\n2. coasterTwo.c\n3. lastnames.c\n4. Quit\n");
    scanf("%d", &option);

    } // End of While Loop


printf("\n");
system("pause");
return 0;
} // End of Main

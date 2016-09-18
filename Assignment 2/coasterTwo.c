// Nathan Guenther
// COP 3223 Section 0001
// Assignment 2 Part B
// 9/23/13
// Allows the user to set a total maximum track length, and the length of each train.
// Then the program calculates each possible combination and determins which solution gives the most passengers.
// Finally calculates an average ratio of passengers divided by the total length of all the trains.

#include <stdio.h>
#include <stdlib.h>

// Set Constants
#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENTH 8
#define CAR_CAPACITY 4

int main()
{

    //   SET ALL THE VARIABLES   //
    //----------------------------//
    int availbletrack, maxtracklength, maxtrainlength;
    int smallcarlength, numsmallcars;
    int trainlength, numtrains;
    int ncars, maxncars;
    int temppassengers, maxpassengers, finalncars;
    float totalpeople, totaltrainlength;
    float ratio, addedratios, counter, temp;
    float averageratio;

    // Ask user about Coaster //
    //----------IMPUT---------//
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
    counter =0 ;
    addedratios =0 ;

            //--------------------------------------//
            //             Main for Loop            //
            // Calculates all possible combinations //
            //--------------------------------------//
            for(ncars = 1; ncars <= (maxncars); ncars++)
            {
                trainlength = 10 + (8 * (ncars-1));
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
    printf("\nYou ride can have at most %d people on it at once time.\n", maxpassengers);
    printf("This can be achieved with trains of %d cars.\n", finalncars);
    printf("AVG Ratio: %.3f\n", averageratio);

system("pause");
return 0;
}

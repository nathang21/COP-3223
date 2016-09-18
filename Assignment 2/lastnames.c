// Nathan Guenther
// COP 3223 Section 0001
// Assignment 2 Part C
// 9/23/13
// Asks the user for the number of names they want to enter, and the names.
// Then the program checks for duplicates and outputs results to user.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Set Variables
    int n, i, repeated;

    // Ask user for imput
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
        repeated = 0;
        for(i = 1; i <= n; i++)
        {
            if(strcmp(lastnames[0],lastnames[i]) == 0 )
            {
                repeated = 1;
            }
        }

        // Final output to user based on calculations
        if(repeated == 1)
            printf("\nFirst name in list is repeated.\n");
        else
            printf("\nFirst name in list is not repeated.\n");


    system("pause");
    return 0;
}

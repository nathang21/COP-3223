#include <stdio.h>
#include <stdlib.h>

// Edited after SI to allow user imput instead of defined H and W

// #define W 3
// #define H 5

int main()
{

    int i,j,k;
    int w, h;

    scanf("%d", &w);
    scanf("%d", &h);

    // Prints a triangular ammount of spaces
    for(i=0;i<h;i++)
    {
        // Don't forget J & K gets reset every time the first for loop runs
        // Edited for only J since it gets reset eveyrtime

        // Prints Spaces before stars, reduces by 1 each time.
        for(j=0;j<i;j++)
            printf(" ");
        // Prints 3 Starts each line.
        for(j=0;j<w;j++)
            printf("*");
        // Moves on to next line
        printf("\n");
    }



system("pause");
return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main ()
{

int totalrow;
int half, rate=1;
int row, col, numstars = 1;

scanf("%d", &totalrow);

half = totalrow/2;

// Main loop. Each Row
for (row=1;row<=totalrow;row++)
{
    //Draw the spaces
    for(col=1;col<=half+1-numstars;col++)
    {
        printf(" ");
    }

    // Draw the stars
    for(col=1;col<=2*numstars-1; col++)
    {
        printf("*");
    }
    // Check for middle
    if(numstars==(half+1))
        rate = -rate;

    // Apply Rate
    numstars=numstars+rate;

    // Next Lines
    printf("\n");

}

system("pause");
return 0;
}

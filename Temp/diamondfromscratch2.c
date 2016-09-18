#include <stdio.h>
#include <stdlib.h>

#define TOTALROW 15

int main()

{
    int row, col, half, i, numstars=1, rate=1;

    half=TOTALROW/2;

    for(row=1;row<=TOTALROW;row++)
    {
        for(col=1;col<=half+1-numstars;col++)
            printf(" ");
        for(col=1;col<=2*numstars-1;col++)
            printf("*");
        if(numstars==(half+1))
           rate = -rate;
        numstars = numstars + rate;
        printf("\n");
    }

    printf("\n");
    system("pause");
    return 0;
}

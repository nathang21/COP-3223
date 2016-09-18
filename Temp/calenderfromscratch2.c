#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numdays, i, start, blankdays;

    printf("Enter the number of days in the month: \n");
    scanf("%d", &numdays);
    printf("Enter the first day of the month (Sun=1 Sat=7: \n");
    scanf("%d", &start);

    blankdays=start-1;
    printf("This Month's Calender is below:\n");
    printf("_S__M__T__W__T__F__S\n");
    for(i=1;i<=blankdays;i++)
        printf("__ ");
    for(i=1;i<=numdays;i++)
    {
        printf("%2d ", i);
        if((i+blankdays)%7==0)
            printf("\n");
    }




printf("\n");
system("pause");
return 0;
}

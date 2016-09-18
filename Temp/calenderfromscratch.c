#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numdays, start, i, blankdays;

    // Ask yset info about current month
    printf("Enter number of days in month:\n");
    scanf("%d", &numdays);
    printf("\nEnter starting day of the week (1=Sun, 7=Sat):\n");
    scanf("%d", &start);
    printf("\n");

    blankdays=start-1;
    printf("The Month Calender is below:\n");
    printf("_S__M__T__W__T__F__S\n");

    for(i = 1; i <= blankdays; i++)
    {
        printf("__ ");
    }

    for(i = 1; i <= numdays; i++)
    {
        printf("%2d ", i);
        if((i+blankdays)%7==0)
            printf("\n");
    }


printf("\n\n");
    system("pause");
    return 0;

}

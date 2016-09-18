#include <stdio.h>
#include <stdlib.h>

int main()
{

int numdays, start, i, blankdays;
int counter, p;
int date, check;
int row = 1;
int sum = 0;
int prime = 1;
int wedsum = 0;

    // Variation ask question for specific date
    printf("Enter a date to check if it falls on a Wednesday\n");
    scanf("%d", &date);
    printf("\n");


    // Ask user for info about current month
    printf("Enter number of days in month:\n");
    scanf("%d", &numdays);
    printf("\nEnter starting day of the week (1=Sun, 7=Sat):\n");
    scanf("%d", &start);
    printf("\n");

    blankdays=start-1;
    printf("The month calender is below:\n");
    printf("__S____M_____T______W_______T________F_________S\n\n");

    counter = 0;
    for(i=1;i<=blankdays;i++)
        {
            printf(" ___");
            counter++;
            for(p=0;p<counter;p++)
            {
                printf(" ");
            }
        }


    for(i=1;i<=numdays;i++)
    {
        if(row==4)
            sum += i;
        printf("%3d ", i);
        counter++;
        for(p=0;p<counter;p++)
        {
            printf(" ");
        }
        if((i+blankdays)%7==0)
        {
            printf("\n");
            counter = 0;
            row++;

        }
        if((date+blankdays)%7==4)
            check=1;

        if((i+blankdays)%7==4)
        {
            wedsum += i;
        }


    }

    printf("\n\n");

    if(check==1)
    {
        printf("%d is a Wednesday.\n", date);
    }
    else
    {
        printf("%d is not a Wednesday.\n", date);
    }


prime = 1;

        for(i=2;i<sum;i++)
        {   if(sum%i==0)
                prime=0;
        }
        // Final Print after checking if not prime
        if(prime==1)
            printf("The sum of %d is Prime\n", sum);
        else
            printf("The sum of %d is not Prime\n", sum);

prime = 1;

        for(i=2;i<wedsum;i++)
        {   if(wedsum%i==0)
                prime=0;
        }
        // Final Print after checking if not prime
        if(prime==1)
            printf("%d the sum of Wednesday's is Prime\n", wedsum);
        else
            printf("%d the sum of Wednesday's is not Prime\n", wedsum);


printf("\n\n");
system("pause");
return 0;
}

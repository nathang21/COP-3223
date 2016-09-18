#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prime, num, i;

    printf("Enter a number to see if prime: \n");
    scanf("%d", &num);
    prime=1;

    for(i=2;i<num;i++)
    {
        if(num%i==0)
            prime=0;
    }


    if(prime==1)
        printf("Yes P\n");
    else
        printf("Not P\n");

    system("pause");
    return 0;
}

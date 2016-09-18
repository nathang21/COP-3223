#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num,i,prime;

    printf("Type In # below to check if it's prime: \n");
    scanf("%d", &num);
    prime=1;

        for(i=2;i<num;i++)
        {   if(num%i==0)
                prime=0;
        }
        // Final Print after checking if not prime
        if(prime==1)
            printf("Yes P\n");
        else
            printf("Not P\n");

system("pause");
return 0;
}

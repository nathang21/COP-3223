#include <stdio.h>
#include <stdlib.h>

int main()
{

int integer = 0;
int squared;


    while(integer != -99)
    {
        scanf("%d", &integer);
        if(integer != -99)
        {
            squared = integer * integer;
            printf("%d  %d\n", integer, squared);
        }
    }

system("pause");
return 0;
}

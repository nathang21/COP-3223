#include <stdio.h>
#include <stdlib.h>

int main()
{
// Still need to exclude product of first product, since previous shouldn't exist
    float current, previous, first, product;
    int firstrun = 1;

    scanf("%f", &current);
    previous = current + 1;
    while(current < previous)
        {
            if(firstrun == 0)
                    printf("%f\n", current * previous);
            previous = current;
            scanf("%f", &current);
            firstrun = 0;

        }

printf("That number was not smaller than the prevous.\n");

system("pause");
return 0;
}

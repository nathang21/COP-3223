#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int val,found,index;
    int SIZE[5];
    SIZE[1]=6;
    SIZE[2]=7;
    SIZE[3]=8;
    SIZE[4]=9;
    SIZE[5]=10;


    printf("What is the number to search for?\n");
    scanf("%d", &val);

        // Assume the length of numbers is SIZE.
        for (index=0; index < 6; index++)
            {
            if (SIZE[index] == val)
            found = 1;
            }

    if (found == 1)
        printf("%d was in the array.\n", val);
    else
        printf("%d was NOT in the array.\n", val);

system("pause");
return 0;

}

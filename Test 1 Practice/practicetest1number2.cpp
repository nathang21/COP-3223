#include <stdio.h>
#include <cstdlib>

int main(void)
{
    int a=5 , b=3, c=4;
    a += 1;

    if (b >  c)
        printf ("a= %d\n", a+4);
    else
        printf ("b= %d\n", b);

    b -= 2;
    if (a <= b)
     {
        printf ("c= %d\n", a+c);
        }
    else
        {
        if (b >  c)
            printf ("d= %d\n", a+c);
        else
            printf ("f= %d\n",  c);
}

    system("pause");
    return 0;
    }


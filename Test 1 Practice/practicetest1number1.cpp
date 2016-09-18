#include <stdio.h>
#include <cstdlib>

int main(void) 
{    
    float f;
    int a,i;
    a = 4;
    a = a - 1;
    printf ("P= %d\n", a);
    a += 2;
    a++;
    a = a % 2;
    printf ("Q= %4d\n", a);
    i=2;
    f=13.0;
    printf ("R= %6.2f\n", f/i);
    a=13;
    printf ("S= %d\n", a/i);
    
system("PAUSE");
    return 0;   
}

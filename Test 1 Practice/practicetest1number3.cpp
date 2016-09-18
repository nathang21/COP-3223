#include <stdio.h>
#include <cstdlib>

int main(void)
{
    int p, i, n;
    p = 2; i = 3;
    scanf("%d", &n);
    while (i <= n)
    {
        if (i < n )
            printf ("b= %d\n", p);
        p = p + i * i ;
        i++;
    }
    for (i=6; i<8; i++)
    {
        printf ("c= %d\n", p+i);
    }
    
   system("pause"); 
    return 0;
}

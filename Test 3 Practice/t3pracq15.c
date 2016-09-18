#include <stdio.h>
#include <stdlib.h>

int f(int a, int d, int b, int c);
int main()
{
    int a = 1, b = 3, c = 2, d = 4;
    a = f(d, a, f(a, c, b+c, d), a+c);
    printf("a= %d b= %d c= %d d= %d\n", a,b,c,d);
    return 0;
}
int f(int a, int d, int b, int c)
{
    int sum;
    b = a + c;
    sum = b - c;
    d = sum + d;
    printf("a= %d, b= %d, c= %d, d= %d\n", a, b, c, d);
    if (sum > a*c)
        return a*c;
    if (sum <= b*c)
        return sum+a;
    return a*b;
}

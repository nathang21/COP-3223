#include <stdio.h>

int f(int c, int b, int a);

int main()
{

    int a = 1, b = 2, c=2;
    a = f(b,  f(a, c, b+c), a+c);
    printf("a=%d b=%d c=%d\n", a, b, c);
    return 0;

}

    int f(int c, int b, int a)
    {

        int sum;

        b = a + c;
        sum = a + b + c;
        printf("a=%d b=%d c=%d\n", a, b, c);
        if (sum > a*c)
            return a*c;
        if (sum <= b*c)
         return b*c;

        return a*b;

    }



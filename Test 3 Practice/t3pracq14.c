#include <stdio.h>
#include <ctype.h>

int main ()
{
    char c;
    while ((c = getchar()) != '9')
    {
        if (isupper(c))
            putchar(('g' + 5 - (c - 'A')));
        else if (islower(c))
            putchar(('P' + 1 + (c - 'a')));
        else
            putchar(c);
    }

    return 0;
}

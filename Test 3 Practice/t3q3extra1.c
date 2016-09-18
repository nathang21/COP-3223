 #include <stdio.h>

  int f(int *b, int d, int a, int *c);

  int main() {

int a = 3, b = 4, c=1, d=2, e=1;

e = f(&b, a, f(&c, c+c, b+b, &d), &a);

printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);

// system("pause");

return 0;

  }

int f(int *b, int d, int a, int *c) {
int sum;
*b = (a + a)% *b;
sum = a- *c;
d = sum + *b;
printf("a=%d b=%d c=%d d=%d\n", a, *b, *c, d);
if (sum > a* *b)
return a* *c;
if (sum <= *b *  *c)
return sum+a;
return a* *b;
}

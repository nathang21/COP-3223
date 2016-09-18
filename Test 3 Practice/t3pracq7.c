#include <stdio.h>

int f(int *a, int c, int b);

int main(void) {


  int a=1, b=3, c=2;



  a =   f(&c, f(&b,a,c),a);



  printf("a= %d b= %d c= %d\n",a,b,c);



  return 0;

}





int f(int *a, int c, int b) {



  *a = *a - 1;



  c = c*2 + (*a);



  b = b - 1;



  printf("a= %d, b= %d, c= %d\n", *a, b, c);



  return c - *a + 1;

}



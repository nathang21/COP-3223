#include <stdio.h>
#include <cstdlib>

int main() {
    int i, NumFromKeyboard, sum;
    
    sum=0;
       for (i=0;i<50;i++)
          {
            scanf("%d", &NumFromKeyboard);
            if (NumFromKeyboard > 100)
                sum += NumFromKeyboard;
          }
       sum *=85;
       printf("The sum is %d.\n", sum);
    

system("pause");
return 0;
}

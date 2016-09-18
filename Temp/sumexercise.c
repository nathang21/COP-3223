#include <stdio.h>
int main() {

    int val = 1;
    int sum = 0;
    
    while (val < 100) {
         sum = sum + val;
         val = val + 2;
    }
    printf("1+3+5+...+99=%d\n",sum);
    
    system("pause");
    return 0;
}

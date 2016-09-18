#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,sum,answer;
    
    sum=0;
    
        for(i=0;i<10;i++)
            {
                scanf("%d", &num);
                    if(num%5==0)
                        {
                            sum += num;
                        }
            } 
    
    answer=sum*100;
    printf("The answer is %d.\n", answer);
    
    system("pause");
    return 0;
}

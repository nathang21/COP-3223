#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,value,sum,answer;
    
    sum=0;
    
        for(i=0;i<41;i++)
        {
        scanf("%d", &num);
        value=num*num;
            if (value>500) 
            {
                sum += num;
            }
        }
    
    answer=sum*sum;
    printf("The Answer is %d.\n", answer);
    
    system("pause");
    return 0;
    
}    

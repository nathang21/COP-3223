#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,sum,result,answer;
    
    sum=0;
    
        for(i=0;i<10;i++)
        {
            scanf("%d", &num);
            result=num*10;
                if(result>85)
                    {
                        sum += num;
                    }
        }           
    
    answer=sum*100;
    printf("The Answer is: %d\n", answer);
    
    
    
system("pause");
return 0;
}

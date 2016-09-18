#include <stdio.h>

int main() {

     double value, total = 0;
     char answer, dummy;

     printf("Does anyone have any money?\n");
     scanf("%c",&answer);
     while (answer == 'y' || answer == 'Y') {

          printf("Enter the amount of your donation.\n");
          scanf("%lf",&value);
          total += value;

          printf("Does anyone have any money?\n");
          scanf("%c%c",&dummy,&answer);
    }

    printf("As a group, you have collected $%lf for beer.\n",
		total);
		
		system("pause");
    return 0;
}

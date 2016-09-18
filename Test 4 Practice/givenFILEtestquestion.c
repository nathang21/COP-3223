// File question on test 4 from practice test 1 number 7 mae ahrder

#include <stdio.h>

void main()
{
    FILE *ifp, *ofp;
    char filename[100];
    int i, num;
    int sum = 0;

    scanf("%s", filename);
    ifp = fopen(filename, "r");

    scanf("%s", filename);
    ofp = fopen(filename, "w");

    for (i = 0; i < 10; i++)
    {
        fscanf(ifp, "%d", &num);
        if (num%5 == 0)
        {
             sum += num;
        }

    }
    sum = sum*100;


    fprintf(ofp, "The Sum is: %d", sum);

    fclose(ifp);
    fclose(ofp);
}

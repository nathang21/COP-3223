#include <stdio.h>

int main()
{
    int i;
    int num;
    int sum = 0;
    char filename[100];

    FILE *ifp, *ofp;

    scanf("%s", filename);
    ifp = fopen(filename, "r");



    for (i = 0; i < 10; i++)
    {
        fscanf(ifp, "%d", &num);
        if (num%5 == 0)
        {
            sum = sum + num;

        }

    }



    sum = sum*100;

    scanf("%s", filename);
    ofp = fopen(filename, "w");

    fprintf(ofp, "Sum = %d", &sum);

    fclose(ifp);
    fclose(ofp);
    return 0;
}



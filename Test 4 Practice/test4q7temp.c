#include <stdio.h>

int main()
{
    int i, j;
    int n;
    int SSN;
    float sum = 0;
    float wages[5];
    char name1[30];
    char name2[30];

    printf("\nEnter Imput Filename\n");
    scanf("%s", name1);
    printf("\nEnter output Filname\n");
    scanf("%s", name2);

    FILE *ifp, *ofp;
    ifp = fopen(name1, "r"); // r means read
    ofp = fopen(name2, "w"); // w means write

    fscanf(ifp, "%d", &n);

    printf("n= %d", n);
    for (i = 0; i < n; i++)
    {
        fprintf(ofp, "Please enter your ssn i = %d \n", i);
        fscanf(ifp, "%d", &SSN);
        for (j = 0; j < 5; j++)
        {
            fscanf(ifp, "%f", &wages[j]);
            sum += wages[j];
        }
    }

    fprintf(ofp, "%f", sum);
    fclose(ofp);
    fclose(ifp);

    return 0;
}


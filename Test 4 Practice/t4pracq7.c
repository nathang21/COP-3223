#include <stdio.h>

int main()
{
    int i, j;
    int n;
    int SSN;
    float sum = 0;
    float wage1, wage2, wage3, wage4, wage5;
    char filename[30];

    FILE *ifp, *ofp;

    printf("\nEnter Imput Filename\n");
    scanf("%s", filename);
    ifp = fopen(filename, "r"); // r means read

    fscanf(ifp, "%d", &n);


    // Try Alternate simply for loop without array, just single for loop, with multiple wage variables
    for (i = 0; i < n; i++)
    {
        fscanf(ifp, "%d", &SSN);
        fscanf(ifp, "%f%f%f%f%f", &wage1, &wage2, &wage3, &wage4, &wage5);
        sum += wage1 + wage2 + wage3 + wage4 + wage5;
    }

    printf("\nEnter output Filname\n");
    scanf("%s", filename);
    ofp = fopen(filename, "w"); // w means write


    fprintf(ofp, "%f", sum);

    fclose(ofp);
    fclose(ifp);

    return 0;
}


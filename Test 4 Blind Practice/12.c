#include <stdio.h>

int main()
{
    int i;
    int num;
    int SSN;
    char filename[30];
    float wage1, wage2, wage3, wage4, wage5;
    float sum = 0;

    FILE *ifp, *ofp;

    scanf("%s", filename);
    ifp = fopen(filename, "r");

    fscanf(ifp, "%d", &num);

    for (i = 0; i < num; i++)
    {
        fscanf(ifp, "%d", &SSN);
        fscanf(ifp, "%f%f%f%f%f", &wage1, &wage2, &wage3, &wage4, &wage5);
        sum += wage1 + wage2 + wage3 + wage4 + wage5;

    }

    scanf("%s", filename);
    ofp = fopen(filename, "w");

    fprintf(ofp, "%f", sum);

    fclose(ifp);
    fclose(ofp);

    return 0;
}

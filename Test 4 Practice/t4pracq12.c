#include <stdio.h>

int main()
{
    int n, i, SSN;
    char filename[30];
    float wages, sum = 0;

    FILE *ifp, *ofp;

    scanf("%s", filename); // open
    ifp = fopen(filename, "r");

    fscanf(ifp, "%d", &n);

    for (i = 0; i < n; i++)
    {
        // fprintf(ofp, "\nEnter your SSN\n");
        fscanf(ifp, "%d", &SSN);
        // fprintf(ofp, "\nEnter your wage\n");
        fscanf(ifp, "%f", &wages);
        sum += wages;
    }

    scanf("%s", filename); // save
    ofp = fopen(filename, "w");

    fprintf(ofp, "\n\nThe Average is: %f\n", sum/n);

    fclose (ifp);
    fclose (ofp);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{




void changepixels(int** imgtemp)
{
    int i, j, numRows = 3, numCols = 3;
    for (i = 0; i < numRows; i++)
        imgtemp[i][ numCols/2] = 255;
    for (j = 0; j < numCols; j++)
        imgtemp[ numRows/2][j] = 255;
    // printf("%d
}
}


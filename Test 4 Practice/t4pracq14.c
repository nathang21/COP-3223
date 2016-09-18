void t4pracq14(int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows ; i++)
    {
        for (j = (numCols / 2); j < numCols; j++)
        {
            PIC1[numCols - i-1][j - (numcols / 2)] = PIC1[i][j];
        }
    }
}


// Plug into copy4.c and run


for (i = 0; i < numRows; i++)
    for (j = numCols / 2; j < numCols; j++)
        PIC1[numRows - 1 - i][j - numCols/2] = PIC1[i][j][;]

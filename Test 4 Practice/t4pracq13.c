void t4pracq13 (int** PIC1, int NumRows, NumCols)
{
    int i, j;
    int NumRows, NumCols;
    for (i = 0; i < (NumRows / 2); i++)
    {
        for (j = (NumCols / 2); j < NumCols; j++)
        {
            PIC1[i][j - (NumCols / 2] = PIC1[i][j];
        }
    }

    for (i = (NumRows / 2); i < NumRows; i++)
    {
        for (j = 0; j < (NumCols / 2); j++)
        {
            PIC1[i][j + (Numcols / 2)] = PIC1[i][j];
        }
    }
}


for (i = 0; i < numRows/2; i++)
    for (j = numCols /2; j< numCols; j++)
        PIC1[i][j - numCols/2] = PIC1[i][j];

for (i = numRols/2; i < numRows; i++)
    for (j = 0; j < numCols /2; j++)
        PIC1[i][j + numCols/2] = PIC1[i][j];

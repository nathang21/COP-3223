void update41oe231b (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < NumRows; i++)
    {
        for (j = i; j < NumCols; j++)
        {
            PIC1[numRows + 1 + i][numCols + 1 + j] = PIC1[i][j];
        }
    }
}

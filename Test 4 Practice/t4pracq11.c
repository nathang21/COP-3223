// Part A
int elevena (int** PIC1, int numRows, int numCols, int Value1)
{
    int i, j;
    counter = 0;
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numCols; j++)
        {
            if (PIC1[i][j] == Value1)
            {
                counter++;
            }
        }
    }

    return counter;
}

// Part B
void elevenb (int** PIC1, int numRows, int numCols, int Value1)
{
    int i, j;
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numCols; j++)
        {
            if (PIC1[i][j] == Value1)
            {
                PIC1[i][j] = 255;
            }
            else
            {
                PIC1[i][j] = 0;
            }
        }
    }
}

// Part C
void elevenc (int** PIC1, int numRows, int numCols, int Value1)
{

}

// Part D
void elevend (int** PIC1, int numRows, int numCols, int Value1)
{
    for (i = 0; i < numRows; i++)
    {
        j = Value1;
        PIC1[i][j] = 255;
    }
    for (j = 0; j < numCols; j++)
    {
        i = Value1;
        PIC1[i][j] = 255;
    }
}

// Part E
void elevene (int** PIC1, int numRows, int numCols, int Value1)
{
    for (i = 0; i < numRows; i++)
    {
        j = i;
        PIC1[i][j] = Value1;
    }
}

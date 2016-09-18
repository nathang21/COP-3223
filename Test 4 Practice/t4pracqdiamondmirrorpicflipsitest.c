/*

            numcols/2
0--------------------------|NumCols
|
|
|
|
|
|---------------------------- numRows / 2
|
|
|
|
|-----------------------------
numRows

0-> numcols /2



Flip Formula
numCols - 1 - j
numCols - 1 - i

Rows Flip
Colums Mirror

*/

// Since Both the rows and cols are flipping (mirror and flip) we use a flip for both i and j
void diamondflipmirror (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows; i++)
    {
        for (j = i; j < numCols; j++)
        {
            PIC1[numCols - 1 - i][numCols - 1 - j] = PIC1[i][j]; // For loops based on source, so IJ goes on right
        }
    }
}


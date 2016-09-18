// Complicatd flip each 8th diagonally


int i, j;

// Top Left (done)
for (i = 0; i < numRows / 2; i++)
    for (j = 0; j < numCols / 4; j++)
    {
        PIC1[numRols - 1 - i][j + (numCols / 4)] = PIC1[i][j];
    }

// Bottom Left
for (i = 0; i < numRows / 2; i++)
    for (j = 0; j < numCols / 4; j++)
    {
        PIC1[numRols - 1 - i][j + (numCols / 4)] = PIC1[i][j];
    }

//Top Right
for (i = 0; i < numRows / 2; i++)
    for (j = 0; j < numCols / 4; j++)
    {
        PIC1[numRols - 1 - i][j + (numCols / 4)] = PIC1[i][j];
    }

// Bottom Right (done)
for (i = numRows / 2; i < numRows; i++)
    for (j = numCols / 2; j < 3*(numCols / 4); j++)
    {
        PIC1[numRows - 1 - i][j + (numCols / 4] = PIC1[i][j];
    }


// 4 Collums, 1st --> 2nd and 3rd --> 4th

// Left
for (i = 0; i < numRows; i++)
    for (j = 0; j < numCols / 4; j++)
{
    PIC1[i][j + numCols / 4] = PIC1[i][j];
}

// Right





// oe231b example diagnoal flip mirror
for (i = 0; i < numRows; i++)
    for (j = 0; j <= i; j++)
{
    PIC1[numCols -1 - i][numRows -1 - j] = PIC1[i][j];
}

// 0e231q example triangle weird flip

for (i = 0; i < numRows; i++)
    for (j = numCols - 1; j >= 0; j--)
{
    PIC1[numCols - 1 - i][j] = PIC1[i][j];
}

// ochangeee1 bottom right corner triangle
for (i = 0; i < numRows / 2; i++)
    for (j = numCols / 2; j < numCols - 1 - i; j++)
        PIC1[i + numRows / 2][j] = PIC1[i][j];

// 01 example
for (i = 0; i < numRows; i++)
    for (j = 0; j < numCols / 2; j++)
        PIC1[i][j] = PIC1[i][numCols / 2 + j];
// onew6
int i, j;
    for (i = 0; i < numRows / 2; i++)
        for (j = (numCols / 2) - 1; j < numCols - i - 1; j++)
            PIC1[numRows/2 + i][numCols/2 + j] = PIC1[i][j];




// ochanged11 + white section
for (i = 0; i < numRows; i++)
    for (j = numCols - 1; j >= numCols - 1 - i; j--)
        PIC1[numCols - 1 - i][numRows - 1 - j] = PIC1[i][j];
    // white line box added
for (i = numRows / 2;  i < 3*numRows/4;i++)
    for(j = 0; j < numCols; j++)
        PIC1[i][j] = 255;
    // 2/4 moved to 3/4 colums
for (i = 0; i < numRows; i++)
    for (j = numCols/4; numColws/2; j++)
        PIC1[numCols - 1 - i][j + numCols/4] = PIC1[i][j];


// oe231b
for (i = 0; i < numRows; i++)
    for (j = 0; j <= i; j++)
        PIC1[numCols - 1 - i][numRows - 1 - j] = PIC1[i][j];

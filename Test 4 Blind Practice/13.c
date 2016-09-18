for (i = 0; i < numRows/2; i++)
    for (j = numCols /2 - 1; j< numCols; j++)
        PIC1[i][numCols/2 - 1 - j] = PIC1[i][j];

for (i = numRols/2; i < numRows; i++)
    for (j = 0; j < numCols /2 - 1; j++)
        PIC1[i][numCols/2 +1 + j] = PIC1[i][j];

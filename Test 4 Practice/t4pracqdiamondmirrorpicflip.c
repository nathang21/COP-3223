void f (int** PIC1, int nrows, int ncols, int value)
{
    int i j
    for (i = 0; i < nrows; i++)
    {
       for (j = i; j < ncols; j++)
        {
            PIC1[nrows + 1 - i][ncols + 1 - j] = PIC1[i][j];
        }
    }
}

// Simply Change j = ncols / 2 to copy and flip the picture vertically down the middle
// Figure out Rotate face weird next class




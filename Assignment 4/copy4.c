#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define  BUFFER_SIZE  70
#define  TRUE          1
#define  FALSE         0

int**  img;
int    numRows;
int    numCols;
int    maxVal;
FILE*  fo1;

void addtopixels(int** imgtemp);
void  writeoutpic(char* fileName, int** imgtemp);
int** readpic(char* fileName);
void  readHeader(FILE* imgFin);
int   isComment(char* line);
void  readImgID(char* line);
void  readImgSize(char* line);
void  readMaxVal(char* line);
int** setImage();
void  readBinaryData(FILE* imgFin, int** imgtemp);

int elevena (int** PIC1, int numRows, int numCols, int Value1);
void elevenb (int** PIC1, int numRows, int numCols, int Value1);
void elevenc (int** PIC1, int numRows, int numCols, int Value1);
void elevend (int** PIC1, int numRows, int numCols, int Value1);
void elevene (int** PIC1, int numRows, int numCols, int Value1);

void t4pracq13 (int** PIC1, int numRows, int numCols);
void t4pracq14 (int** PIC1, int numRows, int numCols);
void update41oe231b (int** PIC1, int numRows, int numCols);
void diamondflipmirror (int** PIC1, int numRows, int numCols);
void zeroone (int** PIC1, int numRows, int numCols);
void oa2312 (int** PIC1, int numRows, int numCols);
void ochangeb1 (int** PIC1, int numRows, int numCols);
void ochanged11 (int** PIC1, int numRows, int numCols);
void onew6 (int** PIC1, int numRows, int numCols);


int main()
{
        char fileName[BUFFER_SIZE];
        int i,j,rows,cols;
        char ci;


        printf("Enter image filename: ");
        scanf("%s", fileName);

        img = readpic(fileName);

        printf("Successfully read image file '%s'\n", fileName);


        // addtopixels(img);
        // elevenb (img, numRows, numCols, 100);
        // t4pracq13 (img, numRows, numCols);
        t4pracq14 (img, numRows, numCols);
        // update41oe231b (img, numRows, numCols);
        // diamondflipmirror(img, numRows, numCols);
        // zeroone (img, numRows, numCols);
        // oa2312 (img, numRows, numCols);
        // ochangeb1 (img, numRows, numCols);
         // ochanged11 (img, numRows, numCols);
        // onew6 (img, numRows, numCols);


        printf("Enter image filename for output: ");
        scanf("%s", fileName);

        writeoutpic(fileName,img);

        free(img);
        img = NULL;

        return(EXIT_SUCCESS);
}

void addtopixels(int** imgtemp)
{
    int i, j;
    for (i = 0; i < numRows ; i++)
    {
        for (j = (numCols / 2); j < numCols; j++)
        {
            imgtemp[numCols - i - 1][j - (numCols / 2)] = imgtemp[i][j];
        }
    }
}

void writeoutpic(char* fileName, int** imgtemp)
{
        int i,j;
        char ci;
        FILE* fo1;

        if((fo1 = fopen(fileName, "wb")) == NULL)
        {
                printf("Unable to open out image file '%s'\n", fileName);
                exit(EXIT_FAILURE);
        }

        fprintf(fo1,"P5\n");
        fprintf(fo1,"%d %d\n", numRows, numCols);
        fprintf(fo1,"255\n");

        for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                  ci   =  (char) (imgtemp[i][j]);
                  fprintf(fo1,"%c", ci);
                }
        }
}




int** readpic(char* fileName)
{
        FILE* imgFin;
        int** imgtemp;

        if((imgFin = fopen(fileName, "rb")) == NULL)
        {
                printf("Unable to open image file '%s'\n", fileName);
                exit(EXIT_FAILURE);
        }

        readHeader(imgFin);


        imgtemp  = setImage();

        readBinaryData(imgFin, imgtemp);

        fclose(imgFin);

        return  imgtemp;

}

void readHeader(FILE* imgFin)
{
        int  haveReadImgID   = FALSE;
        int  haveReadImgSize = FALSE;
        int  haveReadMaxVal  = FALSE;
        char line[BUFFER_SIZE];

        while(!(haveReadImgID && haveReadImgSize && haveReadMaxVal))
        {
                fgets(line, BUFFER_SIZE, imgFin);

                if((strlen(line) == 0) || (strlen(line) == 1))
                        continue;

                if(isComment(line))
                        continue;

                if(!(haveReadImgID))
                {
                        readImgID(line);
                        haveReadImgID = TRUE;
                }
                else if(!(haveReadImgSize))
                {
                        readImgSize(line);
                        haveReadImgSize = TRUE;
                }
                else if(!(haveReadMaxVal))
                {
                        readMaxVal(line);
                        haveReadMaxVal = TRUE;
                }
        }

}

int isComment(char *line)
{
        if(line[0] == '#')
                return(TRUE);

        return(FALSE);
}

void readImgID(char* line)
{
        if(strcmp(line, "P5\n") != 0)
        {
                printf("Invalid image ID\n");
                exit(EXIT_FAILURE);
        }
}

void readImgSize(char* line)
{
        unsigned i;

        for(i = 0; i < strlen(line); ++i)
        {
                if(!((isdigit((int) line[i])) || (isspace((int) line[i]))))
                {
                        printf("Invalid image size\n");
                        exit(EXIT_FAILURE);
                }
        }

        sscanf(line, "%d %d", &numRows, &numCols);
}

void readMaxVal(char* line)
{
        unsigned i;

        for(i = 0; i < strlen(line); ++i)
        {
                if(!((isdigit((int) line[i])) || (isspace((int) line[i]))))
                {
                        printf("Invalid image max value\n");
                        exit(EXIT_FAILURE);
                }
        }

        maxVal = atoi(line);
}

int** setImage()
{
        int** imgtemp;
        unsigned i;

        imgtemp = (int**) calloc(numRows, sizeof(int*));

        for(i = 0; i < numRows; ++i)
        {
                imgtemp[i] = (int*) calloc(numCols, sizeof(int));
        }
        return imgtemp;
}

void readBinaryData(FILE* imgFin, int** imgtemp)
{
        unsigned  i;
        unsigned  j;
        for(i = 0; i < numRows; ++i)
        {
                for(j = 0; j < numCols; ++j)
                {
                            imgtemp[i][j] =
                            fgetc(imgFin);
                }
        }
}


int elevena (int** PIC1, int numRows, int numCols, int Value1)
{
    int i, j;
    int counter = 0;
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
//void elevenc (int** PIC1, int numRows, int numCols, int Value1)
//{

//}

// Part D
void elevend (int** PIC1, int numRows, int numCols, int Value1)
{
    int i, j;
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
    int i, j;
    for (i = 0; i < numRows; i++)
    {
        j = i;
        PIC1[i][j] = Value1;
    }
}

void t4pracq13 (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < (numRows / 2); i++)
    {
        for (j = (numCols / 2); j < numCols; j++)
        {
            PIC1[i][j - (numCols / 2)] = PIC1[i][j];
        }
    }

    for (i = (numRows / 2); i < numRows; i++)
    {
        for (j = 0; j < (numCols / 2); j++)
        {
            PIC1[i][j + (numCols / 2)] = PIC1[i][j];
        }
    }
}

void update41oe231b (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < i; j++)
        {
            PIC1[numRows - 1 - i][numCols - 1 - j] = PIC1[i][j];
        }
    }
}

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

void zeroone (int** PIC1, int numRows, int numCols)
{
   int i, j;
   for (i = 0; i < numRows; i++)
    for (j = 0; j < numCols / 2; j++)
        PIC1[i][j] = PIC1[numCols - 1 - i][numCols / 2 + j];
}

void oa2312 (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows; i++)
        for (j = i; j < numCols; j++)
            PIC1[numCols - 1 - i][numRows - 1 - j] = PIC1[i][j];
}

void ochangeb1 (int** PIC1, int numRows, int numCols)
{
   int i, j;
   for (i = 0; i < numRows; i++)
    for (j = 0; j < numCols / 2; j++)
        PIC1[i][j] = PIC1[numCols - 1 - i][numRows - 1 - j];
}

void ochanged11 (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows; i++)
        for (j = numCols - 1; j >= numCols - 1 - i; j--)
            PIC1[numCols - 1 - i][numRows - 1 - j] = PIC1[i][j];
    // white line box added
    for (i = numRows / 2;  i < 3*numRows/4;i++)
        for(j = 0; j < numCols; j++)
            PIC1[i][j] = 255;
    // 2/4 moved to 3/4 colums
    for (i = 0; i < numRows; i++)
        for (j = numCols/4; j < numCols/2; j++)
            PIC1[numCols - 1 - i][j + numCols/4] = PIC1[i][j];
}
void onew6 (int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows / 2; i++)
        for (j = (numCols / 2) - 1; j < numCols - i - 1; j++)
            PIC1[numRows/2 + i][numCols/2 + j] = PIC1[i][j];
}

void t4pracq14(int** PIC1, int numRows, int numCols)
{
    int i, j;
    for (i = 0; i < numRows; i++)
        for (j = numCols / 2; j < numCols; j++)
            PIC1[numRows - 1 - i][j] = PIC1[i][j];
}


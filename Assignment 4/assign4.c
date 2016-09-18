// Nathan Guenther
// COP 3223 Section 0001
// Assignment 4
// 10/30/13
// Runs a menu that allows the user to imput, manipulate, and output pictures.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define  BUFFER_SIZE  70
#define  TRUE          1
#define  FALSE         0



int option, value;
// Picture Arrays for imput and output
int**  img1;
int**  img2;
int**  img3;

// To output new picture arrays
int** out1;
int** out2;
int** out3;
char* tempName;

// Sobel function
int** temppicx, temppicy;
int**  img, sobelout;

int    numRows;
int    numCols;
int    maxVal;
FILE*  fo1;

char fileName[BUFFER_SIZE];
int i,j,rows,cols;
char ci;

// Functions
void addtopixels(int** imgtemp, int value);
void  writeoutpic(char* fileName, int** imgtemp);
int** readpic(char* fileName);
void  readHeader(FILE* imgFin);
int   isComment(char* line);
void  readImgID(char* line);
void  readImgSize(char* line);
void  readMaxVal(char* line);
int** setImage();
void  readBinaryData(FILE* imgFin, int** imgtemp);
void subtract(int** img1, int** img2, int** img3);
void sobelfunc(int** pic, int** edges, int** tempx, int** tempy);





// Main Menu Function
int main()
{
    // Initial Display Menu
    printf("Welcome to the Picture Manipulation Program.\n\n");
    printf("1. Option 1 (Brighten Pic)\n2. Option 2 (Subtract Pic)\n3. Option 3 (Highlight Edge Pic)\n4. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    // While Loop for each option
    while (option != 4)
    {
        // Option 1 Change Brightness
        if (option == 1)
        {
            printf("Enter image filename: ");
            scanf("%s", fileName);

            img1 = readpic(fileName);

            printf("Successfully read image file '%s'\n", fileName);
            printf("Enter value to Brighten Picture by: ");
            scanf("%s", &value);

            addtopixels(img1,value);

            printf("Enter image filename for output: ");
            scanf("%s", fileName);

            writeoutpic(fileName,img1);

            tempName = ("out1.pgm");
            writeoutpic(tempName,img1);

            free(img1);
            img1 = NULL;

            // return(EXIT_SUCCESS);
        }

        // Option 2 Subtract Two Images
        else if (option == 2)
        {
            printf("Enter First image filename: ");
            scanf("%s", fileName);
            img1 = readpic(fileName);

            printf("Enter Second image filename: ");
            scanf("%s", fileName);
            img2 = readpic(fileName);

            printf("Successfully read image files.\n");

            img3 = setImage();
            subtract(img1, img2, img3);

            printf("Enter image filename for output: ");
            scanf("%s", fileName);
            writeoutpic(fileName,img3);

            tempName = ("out2.pgm");
            writeoutpic(tempName,img3);

            free(img1);
            img1 = NULL;
            free(img2);
            img2 = NULL;
            free(img3);
            img3 = NULL;
        }

        // Option 3 Edge Highlighter
        else if (option == 3)
        {
            printf("Enter image filename: ");
            scanf("%s", fileName);
            img1 = readpic(fileName);

            sobelout= setImage();
            temppicx= setImage();
            temppicy= setImage();

            sobelfunc(img1,sobelout,temppicx,temppicy);

            printf("Enter image filename for output: ");
            scanf("%s", fileName);

            writeoutpic(fileName,sobelout);

            tempName = ("out3.pgm");
            writeoutpic(tempName,sobelout);


            free(img1);
            img1 = NULL;
        }

        // Solution for Incorrect Imput
        else if (option != 4)
        {
            // Output Error for invalid Option
            printf("\nSorry that is not a valid menu option.\n\n");
        }

        // Reprint Main Menu
        printf("\n\nWelcome to the Picture Manipulation Program.\n\n");
        printf("1. Option 1 (Brighten Pic)\n2. Option 2 (Subtract Pic)\n3. Option 3 (Highlight Edge Pic)\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

    } // End of While Loop

    // Output Final Goodbye Message
    printf("\n\nThank You for using the software. Bye for now.\n\n");

}
        //                  //
        // Function Section //
        // ---------------- //
void addtopixels(int** imgtemp, int value)
{
        int i,j;

        for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                  imgtemp[i][j] += value;
                }
        }
}

void subtract(int** img1, int** img2, int** img3)
{
    int i,j;

        for (i=0;i<numRows;i++)
        {
            for (j=0;j<numCols;j++)
                {
                  img3[i][j] = img1[i][j] - img2[i][j];
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

void sobelfunc(int** pic, int** edges, int** tempx, int** tempy){

        int maskx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
        int masky[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
        int maxival;




        int i,j,p,q,mr,sum1,sum2;
        double threshold;


        mr = 1;


        for (i=mr;i<numRows-mr;i++)
        { for (j=mr;j<numCols-mr;j++)
          {
             sum1 = 0;
             sum2 = 0;
             for (p=-mr;p<=mr;p++)
             {
                for (q=-mr;q<=mr;q++)
                {
                   sum1 += pic[i+p][j+q] * maskx[p+mr][q+mr];
                   sum2 += pic[i+p][j+q] * masky[p+mr][q+mr];
                }
             }
             tempx[i][j] = sum1;
             tempy[i][j] = sum2;
          }
        }

        maxival = 0;
        for (i=mr;i<numRows-mr;i++)
        { for (j=mr;j<numCols-mr;j++)
          {
             edges[i][j]=(int) (sqrt((double)((tempx[i][j]*tempx[i][j]) +
                                      (tempy[i][j]*tempy[i][j]))));
             if (edges[i][j] > maxival)
                maxival = edges[i][j];

           }
        }



        for (i=0;i<numRows;i++)
          { for (j=0;j<numCols;j++)
            {
             edges[i][j] = ((edges[i][j]*1.0) / maxival) * 255;

            }
          }
}

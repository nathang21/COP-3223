// Arup Guha
// 2/4/2010
// Written in COP 3223 Class
// Prints out a "backwards" triangle of an arbitrary size.
#include <stdio.h>

int main() {
    int n;
    
    // Get user input.
    printf("How big do you want your backwards triangle?\n");
    scanf("%d", &n);
    
    // Number of spaces on the first row.
    int spaces = n-1;
    
    // Go through each row with of spaces, last row has 0.
    while (spaces >= 0) {
          
        // Print the right number of spaces.  
        int col = 1;
        while (col <= spaces) { 
            printf(" ");
            col++;
        }
        
        // This is the correct number of stars.
        int stars = n-spaces;
        
        // Now print these.
        col = 1;
        while (col <= stars) { 
            printf("*");
            col++;
        }
        
        // Go to the next line, and adjust the number of spaces.
        printf("\n");
        spaces--;
    }
    
    system("PAUSE");
    return 0;
}

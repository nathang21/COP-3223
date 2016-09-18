// Arup Guha
// 10/3/08
// Code from Array lecture for COP 3223 - generates random numbers, stores
//      them into an array, then reverses them in the array and prints.
#include <stdio.h>
#include <time.h>

#define SIZE 10

int main() {
    
    srand(time(0));

    int index, temp, numbers[SIZE];
    
    // Fill array with random values from 0 to 99.
    for (index=0; index<SIZE; index++)
        numbers[index] = rand()%100;
        
    // Print original array values.
    printf("Original Array Vals: ");
    for (index=0; index<SIZE; index++)
        printf("%d ", numbers[index]);
    printf("\n");

    for (index=0; index<SIZE/2; index++) { 
        temp = numbers[index];
        numbers[index] = numbers[SIZE - 1 - index];
        numbers[SIZE - 1 - index] = temp;
    }

    // Print reversed array values.
    printf("Reversed Array Vals: ");
    for (index=0; index<SIZE; index++)
        printf("%d ", numbers[index]);
    printf("\n");
    
    system("PAUSE");
    return 0;
}

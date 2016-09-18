/*****
* Taylor Kourim
* COP3223      Feb 8, 2011
* Determine whether or not you get a scholarship
* [Example of logical and]
*/

#include <stdio.h>

// The minimum requirements to be eligible for the scholarship
#define MIN_GPA 3.2
#define MIN_SAT 1200

int main(void) {
    
    // GPA has to be a float because it has a decimal, SAT score is always an integer
    float gpa;
    int sat;
    
    // Prompt user for values
    printf("Enter your GPA:\n");
    scanf("%f", &gpa);
    printf("Enter your SAT:\n");
    scanf("%d", &sat);
    
    // Logical and && is used because BOTH requirements need to be met
    if (gpa >= MIN_GPA && sat >= MIN_SAT) 
       printf("Congratulations! You're eligible for the scholarship.\n");
    // Logical or || is used because either requirement could be true for this statement:
    else if (gpa >= MIN_GPA || sat >= MIN_SAT) 
       printf("You're close, you meet one of the requirements.\n");
    // The user meets neither of the requirements
    else
       printf("Sorry, you are not eligible\n");
     
     system("pause"); 
    return 0;
}

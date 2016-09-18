// Arup Guha
// 2/3/09
// Several basic examples illustrating for loops.

#include <stdio.h>

int main() {
    
    /**************** Cheering Several Times *************************/
    int num_times, index;
    
    // Read in number of times to cheer.
    printf("How many times do you want to cheer for UCF?\n");
    scanf("%d", &num_times);
    
    // Repeat the cheer exactly that many times!
    // Note: We print index to show what is going on during each loop
    //       iteration.
    for (index=0; index<num_times; index++) {
        printf("%d. Go UCF!!!\n", index+1);
    }
    
    
    /******************* Calculating an Exponent **********************/
    int base, exp;
    
    // Get the base and exponent from the user.
    printf("Enter the base.\n");
    scanf("%d", &base);
    printf("Enter the exponent.\n");
    scanf("%d", &exp);
    
    // Start our answer.
    int answer = 1;
    
    // Multiply answer by base the correct number of times.
    // The printf is so you can see what answer equals at each step.
    for (index = 0; index<exp; index++) {
        answer = answer*base;
        printf("power=%d, answer = %d\n", index+1, answer); 
    }
    
    // Print out the final answer.
    printf("%d raised to the %d = %d\n", base, exp, answer);
    
    /******************* Calculating a Factorial *********************/
    int n;
    
    // Get n from the user.
    printf("What factorial do you want to calculate?\n");
    scanf("%d", &n);
    
    // Start our answer.
    answer = 1;
    
    // Multiply answer by 1, then 2, then 3, ...
    // The printf is so you can see what answer equals at each step.
    for (index = 1; index<=n; index++) {
        answer = answer*index;
        printf("multiplier=%d, answer = %d\n", index, answer); 
    }
    
    // Print out the final answer.
    printf("%d! = %d\n", n, answer);
    
    /**************** Calculating the sum of 1+2+3...+n ***************/
    
    // Get n from the user.
    printf("To what positive integer do you want to sum?\n");
    scanf("%d", &n);
    
    // Start our answer, it's 0 since we're adding.
    answer = 0;
    
    // Add 1, then 2, then 3, ... to answer.
    // The printf is so you can see what answer equals at each step.
    for (index = 1; index<=n; index++) {
        answer = answer+index;
        printf("adding %d, answer = %d\n", index, answer); 
    }
    
    // Print out the final answer.
    printf("1+2+3+...+%d = %d\n", n, answer);
    
    /************** Calculating the sum with fancy printing *************/
    
    // Get n from the user.
    printf("To what positive integer do you want to sum?\n");
    scanf("%d", &n);
    
    // Start our answer, it's 0 since we're adding.
    answer = 0;
    
    // Add 1, then 2, then 3, ... to answer.
    // The printf is so you can see what answer equals at each step.
    for (index = 1; index<=n; index++) {
        answer = answer+index;
        
        // Print this number to add.
        printf("%d", index);
        
        // Only print the plus sign if the last number printed wasn't the last.
        if (index < n) {
            printf(" + ");
        }
    }
    
    // Print out the final answer.
    printf(" = %d\n", answer);
    
    system("pause");
    return 0;
}

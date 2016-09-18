// Arup Guha
// 9/23/04
// Sample code that shows the use of the rand() function and uses a loop.
// The program asks the user to guess a secret number in between 1 and 
// 100. After each guess the user is told if their guess is too high, too
// low, or correct, at which point the program stops.

#include <stdio.h>
#include <time.h>

int main(void) {

    int secret, guess;
    int numguesses = 0;

    // Seeds the random number generator.
    srand(time(0));

    // Create the secret number.
    secret = 1 + rand()%100;

    // Keep on playing until the user has gotten the number.
    do {

        // Get the current guess.
        printf("Enter your next guess.(1 to 100)\n");
        scanf("%d", &guess);
        numguesses++;

        // Print out the appropriate message for each choice.
        if (guess < secret)
            printf("You need to guess higher. Try again!\n");
        else if (guess > secret)
            printf("You need to guess lower. Try again!\n");
    
    } while (guess != secret);

    printf("You guessed correctly with %d guesses.\n", numguesses);
    system("pause");
    return 0;
}

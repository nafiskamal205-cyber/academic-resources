// Program to create a simple guess number game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int guessNumber, randomNumber;
    int startingRange = 1;
    int endingRange = 5;
    int attempt = 0;

    srand(time(NULL));  // Seed the random number generator
    randomNumber = rand() % endingRange + 1;  // Generate a random number between 1 and 5

    printf("\nGuess Number Game\n");

    while(1)
    {
        printf("Guess number between %d-%d:", startingRange, endingRange);
        scanf("%d", &guessNumber);

        if(guessNumber < 1 || guessNumber > 5)
        {
            printf("Invalid guess! Enter a number between %d and %d.\n", startingRange, endingRange);
            continue;  // Prompt the user to guess again
        }
        attempt++;

        if(guessNumber > randomNumber)
        {
            printf("Too high! Try again.\n");
        }
        else if(guessNumber < randomNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the correct number.\n");
            printf("The correctnumber was: %d\n", randomNumber);
            printf("Total valid attempt: %d\n", attempt);
            break;  // Exit the loop if the guess is correct
        }
    }


    return 0;

}

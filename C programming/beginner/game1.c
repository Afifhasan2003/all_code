#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int number, guess, i = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("\n The number is %d", number);
    do
    {
        printf("\n guess the number:");
        scanf("%d", &guess);

        if (guess < number)
        {
            printf("Number is bigger");
        }
        else if (guess > number)
        {
            printf("number is smaller");
        }
        else
        {
            printf(" You guessed right");
        }
        i = i + 1;

    } while (guess != number);

    printf(" \n the number of guesses: %d", i);

    return 0;
}
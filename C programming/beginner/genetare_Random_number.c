#include <stdio.h>
#include <stdlib.h> //this defines rand()
#include <time.h>   //this define srand()

int main()
{

    int number;
    srand(time(0)); // this has to be before number=rand()
    number = rand() % 100 + 1;
    // int randomNumber = rand() % range + min; // Generate a random number within the specified range

    printf(" A random number is : %d", number);

    return 0;
}
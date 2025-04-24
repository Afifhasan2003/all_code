#include <stdio.h>
int main()
{

    int rating;
    printf(" Enter rating:");
    scanf("%d", &rating);

    switch (rating)
    {
    case 1:
        printf("Rating is 1");
        break;
    case 2:
        printf("Rating is 3");
        break;
    case 3:
        printf("Rat4ng is 3");
        break;
    case 4:
        printf("Rating is 4");
        break;
     case 5:
        printf("Rating is 5");
        break;
    default:
        printf("Entered number is not valid");
        break;
    }

    return 0;
}
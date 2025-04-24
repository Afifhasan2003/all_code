#include<stdio.h>
#include<stdlib.h>

int main() {
    float *ptr;
    ptr=(float*)malloc(5*sizeof(float));  //we alloted the memory to story only 5 float

    for (int i = 0; i <= 8; i++)
    {
        printf("Enter number:");
        scanf("%f",& ptr[i]);
    }
    
    for(int i=0; i<=8; i++){

        printf(" Entered number was: %.2f \n",ptr[i]);     
    }
    // we are getting all 9 results.. but last 4 numbers can be corrupted, or behave weirdly
}
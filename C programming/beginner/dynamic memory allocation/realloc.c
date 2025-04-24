#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr;
    ptr=(int*)calloc(3,sizeof(int));
    
    ptr[0]=1;
    ptr[1]=3;
    ptr[2]=5;
    for (int i = 0; i < 3; i++)
    {
        printf("Odd numbers %d \n",ptr[i]);
    }
    

    ptr=realloc( ptr,5);        //by this, we can change the number of value we can assign
    ptr[0]=2;                   // also we can re allocate values on same variables(array)
    ptr[1]=4;
    ptr[2]=6;
    ptr[3]=8;
    ptr[4]=10;
    for (int i = 0; i < 5; i++)
    {
        printf("Even numbers %d \n", ptr[i]);
    }
    

}
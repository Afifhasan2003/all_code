#include<stdio.h>
int main(){

int position[4];

    int *location= &position[0];

for ( int i = 0; i < 5; i++)
{

    printf("Enter %d th position  ",i+1);
    scanf("%d", location +i);
  //  printf("check i= %d \n",i);
}

for (int i = 0; i < 5; i++)
{
    printf(" %d th student's position is %d \n",i, position[i]);
    //printf(" location of that info %u \n", (location +i));
}



}
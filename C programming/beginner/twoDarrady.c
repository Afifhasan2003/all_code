#include<stdio.h>

int main() {

    int marks[2][3]; 
    marks[0][0]=91;
    marks[0][1]=92;
    marks[0][2]=93;
    marks[1][0]=94;
    marks[1][1]=95;
    marks[1][2]=96;
   // printf("1st student's  1st number: %d", marks[0][0]);
    int i,j;

    for (int i = 0 ; i <=2  ; i++ )
    {
        printf("1st student's numbers are: %d \n", marks[0][i]);
    }
    
     for (int i = 0 ; i <=2  ; i++ )
    {
        printf("1st student's numbers are: %d \n", marks[1][i]);
    }
}
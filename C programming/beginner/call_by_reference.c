#include<stdio.h>

void callByValue(int n);

void callByRef(int *n);
int main() {

    int  number=5;
    int number2=5;
    //callByValue(number);
    callByRef( &number2);
    printf("number is still %d \n",number);
    
 
return 0;
}
void callByValue(int n){
    printf("value of n at first: %d \n",n);
    n=n+10;
    printf("value of n after: %d \n",n);
    
} 

void callByRef(int *n){
    printf("\n \n value of n at first %d \n", *n);
    *n= *n+10;
    printf("value of n after %d \n", *n);
    
}
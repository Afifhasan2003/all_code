#include<stdio.h>

int fact(int x);
int main() {

    int a;
    printf("Enter number");
    scanf("%d", &a);
    
    printf("The factorail of %d is %d",a,fact(a));
    
 
 
return 0;
}

int fact(int x){


    if (x==1 || x==0)
    {
        int factorial= 1;   //base condition
    }  
    else
    {
        int factorial= x * fact(x-1);
    }
    
    
}
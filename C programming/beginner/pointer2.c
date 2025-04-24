#include<stdio.h>

int manyoutput( int a, int b, int *sum, int *prod, int *avg );
int main(){
    int a=3,b=5, sum, prod,avg;

    manyoutput(a,b,&sum, &prod, &avg );

    printf("sum is %d , product is %d , average is %d", sum, prod, avg);
    

}

int manyoutput( int a, int b ,int *sum, int *prod, int *avg){

    *sum=a+b;
    *prod=a*b;
    *avg= *sum /2; 
    
}

















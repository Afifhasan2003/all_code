#include<stdio.h>

void math(int a, int b, int *sum,int *prod, float *avg );
int main() {

     int a,b,sum,prod;
     float avg; 
    a=5;
    b=6;

    math(a,b,&sum,&prod, &avg);

    printf("sum is = %d \n",sum);
    printf("product is =%d \n", prod);
    printf("average is =%f \n",avg);
    
    
    
 
return 0;
}
void math(int a, int b, int *sum,int *prod, float *avg ){

*sum= a+b;
*prod=a*b;
*avg= (float)(*sum)/2;

}
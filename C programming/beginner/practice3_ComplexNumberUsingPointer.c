#include<stdio.h> 
#include<math.h>

struct complex{
    int real;
    int img;
};
int main(){

    struct complex number1={3,4};
    struct complex *ptr=&number1;

    // printf(" real part is %d \n", number1.real);
    // printf(" imaginary part is %d \n", number1.img);

    float modulas=sqrt(pow(number1.real,2) + pow(number1.img,2));

   printf(" real part is %d \n", ptr->real);
   printf(" imaginary part is %d \n", ptr->img);
    printf(" modulas is %.3f", modulas);
    
}
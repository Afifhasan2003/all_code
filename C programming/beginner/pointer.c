#include<stdio.h>
// int main() {
//     int a=20;
//     int *b=&a;
//     printf("%u \n",&a);
//     printf("%u \n",b);
//     printf("%u \n",&b);
//     printf("%u \n", *b);
//     printf("%u", *(&a));
// }


int main(){

    int i=5;
    int *point1=&i;
    int **point2=&point1;

    printf("value of i: %d \n",i);
    printf("value of i: %d \n", *point1);
    printf("value of i: %d \n",**point2);
    printf("value of *point2 : %d \n",*point2 );  //this is address of i
    
    
    

    printf("initial value: %u \n",**point2);

    printf(" if use one * : %u \n",*point2); 
    printf("if use no * : %u \n",point2);      //this is address of point1
    printf(" adress of i : %u \n", &i);
    printf(" adress of point1 : %u \n", &point1);
    printf(" adress of point1 : %u \n", &point2);


}
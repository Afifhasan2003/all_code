#include<stdio.h>

// void swapValue(int a, int b);
void swapRef(int *a, int *b);
int main() {


     int a,b;
     printf("Enter value of a:");
     scanf("%d", &a);
     printf("Enter value of b:");
     scanf("%d", &b);
      
    //function calling
    // swapValue(a,b);
    swapRef(&a,&b);

     printf("value of a: %d \n value of b: %d",a,b);

     
 
return 0;
}
void swapRef(int *a, int *b){     //a and b is address
    int temp=*a;
    *a= *b;
    *b=temp;
    printf("value of a: %d \n value of b: %d \n",*a,*b);

}


// void swapValue(int a, int b){
//     int temp=a;
//     a=b;
//     b=temp;

//     printf("value of a: %d \n value of b: %d \n",a,b);
    
// }
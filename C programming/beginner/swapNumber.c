#include<stdio.h>
int main() {

    int a,b;
     printf("Enter value of a:");
     scanf("%d", &a);
     printf("Enter value of b:");
     scanf("%d", &b);
      
    int temp;
    temp=a;
    a=b;
    b=temp;

    printf("value of a is %d \n",a);
    printf("value of b is %d \n",b);
    
 
 
return 0;
}
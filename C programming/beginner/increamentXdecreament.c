#include<stdio.h>
int main() {

     int a=5;

   
      
    // printf("%d \n",a);
    // printf("%d \n",a++);
    // printf("%d \n",a);
    // printf("%d \n",++a);
    
    
    printf(" %d %d %d \n ",a,a++ ,++a);
    printf(" %d %d %d ",a,++a,a++);
 
 //The output of the provided code may vary depending on the order of evaluation of expressions,
 // which is undefined behavior in C due to the lack of a defined sequence point between 
 //the evaluations of the arguments in the printf function.
 // it's clearer and safer to split these operations into separate statements.
 
return 0;
}
#include<stdio.h>

void address(int n);
int main() {

     int i=5;
     printf("adress of i is %u \n",&i);
     
      address(i);
 
 
return 0;
}
void address(int n){

    printf("adress of i is %u",&n);
    
}

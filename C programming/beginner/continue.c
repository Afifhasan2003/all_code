#include<stdio.h>
int main() {

     for (int i = 0; i < 100; i++)
     {
        
        if (i==8)
        {
            continue;
        }
        printf("number is : %d \n",i);      //8 will be skipped


     }
      
 
  
return 0;
}
#include<stdio.h>
int main() {

     int student[2][3][4]; 

     for (int i = 0; i < 2; i++)
     {
        for (int j= 0; j < 3; j++)  
        {
            for (int k = 0; k < 4; k++)
            {
                printf("The adress of [%d][%d][%d] = %d \n", i,j,k,&student[i][j][k]);
                
            }
            
        }           //as we can see from the output,, 4byte increament
        
     }
     
 
 
return 0;
}
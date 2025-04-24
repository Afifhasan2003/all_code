#include<stdio.h>
int main() {
    int n;
    printf("Enter line numbers:");
    scanf("%d", &n);
    
    
     for (int i = 1; i < 2*n; i=i+2)
     {
        for (int j = 1; j<=i; j++)
        {
            printf(" *");
            
        }
        printf("\n");
        
     }
      
 
 
return 0;
}
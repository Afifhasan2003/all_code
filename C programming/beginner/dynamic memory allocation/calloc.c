//difference is here every variable is given 0 before anything is inputed

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr,n;
    printf("how many integer do u want to input:");
    scanf("%d", &n);

    ptr=(int *) calloc(n,sizeof(int));

    for (int i = 0; i < n-2; i++)     //this will take 2 less input. so the rest two will be zero 
    {
        printf("Enter value:");
        scanf("%d", &ptr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d th number is %d \n", i+1,ptr[i]);
    }
    

return 0;
}
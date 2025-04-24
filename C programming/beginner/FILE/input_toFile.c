#include<stdio.h>
int main() {

     FILE *detail;
     detail = fopen("raff.txt","w") ;
    int income;
    char name[40];
     for (int i = 0; i < 5; i++)
     {
        printf("Enter name:");
        scanf("%s", name);
        printf("Enter income:");
        scanf("%d", &income);

        fprintf(detail,"%s,",name);
        fprintf(detail,"%d \n",income);
        
     }
     fclose(detail);
 
 
return 0;
}
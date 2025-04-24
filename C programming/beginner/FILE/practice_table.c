#include<stdio.h>
int main() {

    FILE *table;
    table=fopen("table.txt","w");

    int num,i=1;
    printf("Enter number:");
    scanf("%d", &num);
    
    while (i<=10)
    {
            fprintf(table,"%d x %d = %d \n", num,i,num*i);
            i++;

    }
    
     fclose(table);
 
 
return 0;
}
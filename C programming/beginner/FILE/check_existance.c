#include<stdio.h>
int main() {

     int num1,num2, num3;

     FILE *number;          
     number=fopen("numbers.txt","r");

     if (number==NULL)
     {  
        printf("File does not exist");
    } else{
        fscanf(number,"%d",&num1);
     fscanf(number, "%d", &num2);    
     fscanf(number, "%d", &num3);

    fclose(number);        
    printf("numbers are %d, %d , %d", num1, num2, num3);
     
    fclose(number);
    }
     
 
return 0;
}
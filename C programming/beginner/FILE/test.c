#include<stdio.h>

int main(){

    FILE *fptr;
    fptr=fopen("test.txt", "r");

    int a, b;
     fscanf(fptr,"%d", &a);
     printf("%d \t",a);
     fscanf(fptr,"%d", &a);
     printf("%d \t",a);
     fscanf(fptr,"%d", &a);
     printf("%d \t",a);
     fscanf(fptr,"%d", &a);
     printf("%d \t",a);
     fscanf(fptr,"%d", &a);
     printf("%d \t",a);
    // while (a!=EOF)
    // {
    //     printf("%d \t",a);
    //     a=fgetc(fptr);
    // }
    fclose(fptr);
    
}
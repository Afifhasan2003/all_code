#include<stdio.h>

int main() {

    FILE *fptr;
    fptr= fopen("sum_replace.txt","r");

    int a,b;

    fscanf(fptr,"%d",&a);
    fscanf(fptr,"%d",&b);

    fclose(fptr);

    fptr=fopen("sum_replace.txt","w");

    fprintf(fptr,"%d",a+b);
    
}
#include<stdio.h>

int main(){

    FILE *fptr;
    fptr=fopen("read.txt", "r");
    
    
    char ch;
    fscanf(fptr,"%c", &ch);
    printf("%c",ch);
    fscanf(fptr,"%c", &ch);
    printf("%c",ch);
    fscanf(fptr,"%c", &ch);
    printf("%c",ch);
    fscanf(fptr,"%c", &ch);
    printf("%c",ch);
    fscanf(fptr,"%c", &ch);
    printf("%c",ch);
    
    // printf("%c",fgetc(fptr));       //automatically reads the next character
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));
    // printf("%c",fgetc(fptr));

    fclose(fptr);

}
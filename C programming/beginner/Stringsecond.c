#include<stdio.h>

int main() {

    char name[20];
    printf("Enter name:");
    scanf("%s",name);           //name is an array, so it does not need & 
        //scanf can not take more than one word 
        
    printf(" name is : %s",name);
    return 0;

       // OR 

   // char name[100];
    //gets(name);     //gets is unsafe but works
    //fgets(name, 100,stdin);
    //puts(name);
}
#include<stdio.h>
int main() {

     FILE *write;
     write=fopen("write.txt","w");

     int num=40;

     fprintf(write,"inputing is this easy \n number is : %d",num) ;
    
    fclose(write);
 
return 0;
}
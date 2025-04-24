#include<stdio.h>

void encrypt( char *subject);
int main() {

    char subject[]="come on bee";
      
    encrypt(subject);
    printf("encrypted message is : %s",subject);
    
 
 
return 0;
}
void encrypt( char *subject) {
    int i=0;
    char *btr=subject;
    while (*btr != '\0')   //dont use ( subject[i])
    {
         *btr=*btr+1;
         btr++;
    }
    
}
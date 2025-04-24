#include<stdio.h>

void encrypt( char *subject);
int main() {

    char subject[]="dpnf!po!cff";
      
    encrypt(subject);
    printf("encrypted message is : %s",subject);
    
 
 
return 0;
}
void encrypt( char *subject) {
    int i=0;
    char *ptr=subject;
    while (*ptr != '\0')   //dont use ( subject[i])
    {
         *ptr=*ptr-1;
         ptr++;
    }
    
}
#include<stdio.h>
#include<string.h>

void check(char sentence [] ,char ch);
int main(){
    char letter; 
    char input[]="check for letter";
    printf("which letter to check :");
    scanf("%c", &letter);
    check(input, letter );

} 

void check(char sentence[] , char ch){


    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i]==ch)
        {
            printf("%c is present \n", ch);
            return;
           
        }
      }
         
    printf(" %c is not present", ch);    
     
               
   
    
}
#include<stdio.h>
#include<string.h>

int counter(char str[]);
int main(){

    char input[100];
    printf("Input any sentence:");
    fgets(input,100,stdin);
    int total= strlen(input);
    int vo=counter(input);
    printf("number of vowels are: %d \n",vo);
    printf("number of consonant are: %d",total - vo);

} 

int counter(char str[]){

    int count=0;
    for (int i = 0; str[i] !='\0' ; i++)
    {
        if (
            str[i]=='a'|| str[i] =='e' || str[i] =='i'|| str[i] =='o'|| str[i] =='u' || 
            str[i]=='A'|| str[i] =='E' || str[i] =='I'|| str[i] =='O'|| str[i] =='U'
         )
        {
            printf("%c \n",str[i]);
            count++;
        }
        
    }
    return count;

}
#include<stdio.h>
#include<string.h>

void password(char givenPass[]);
int main() {

    char pass[100];
    printf("Enter new pass:");
    scanf(" %s", pass);


    password(pass);

}

void password(char givenPass[]){
    char newPass[100];
    char salt[]="123";
    strcpy(newPass, givenPass);
    strcat(newPass,salt);
    printf("Salted password is :");
    puts(newPass);
}
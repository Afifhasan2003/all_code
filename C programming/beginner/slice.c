#include<stdio.h>
#include<string.h>
 
//cut 1st and last letter 

void slice(char word[], int n , int m);
int main () {

    char str[100];
    printf("Enter word:");
    scanf("%s", str);
    int n= strlen(str)-2;
    slice(str, 1, n);

}

void slice(char *word,int m ,int n){
    char newstr[100];
    int j=0;
    for (int i = m ; i <=n ; i++ , j++)
    {
        newstr[j]=word[i];

    }
    newstr[j]='\0';     //making it a string
    puts(newstr);

}
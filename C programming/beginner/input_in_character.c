#include<stdio.h>
#include<string.h>
int main(){

    char str[100];
    char ch;
    int i=0, n=0;

    while (ch != '\n')
    {
        scanf("%c", &ch);
        str[i]=ch;
        i++;
        n=n+1;
    }
    // printf("value of i: %d \n",i);
    // printf("value of n : %d \n",n);

    // str[i]='\0';

    // puts(str);
    for (int j= 0; j <i ; j++)
    {
        printf("%c", str[j]);
    }
    return 0;
}
#include<stdio.h>

// int counter(char arr[]);
// int main(){

//     char line[100];
//     fgets(line, 100,stdin);

//     printf("Word number is %d", counter(line) );
// } 

// int counter(char arr[]){

//     int count=0;
//     for (int i = 0; arr[i] != '\0' ; i++)
//     {
//         count++;
//     }
    
//     return count -1 ; 
// }

#include<string.h>
int main(){

    char name[100] ;
   fgets(name, 100, stdin);

    int length= strlen(name)-1;  //we have to decrease one because fgets incluede a "\n" with it

    printf("word length is %d", length);
    return 0;
}
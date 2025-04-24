#include<stdio.h>

#include<string.h>

int main() {

char first[]={"AAAB"};
char second[]={"AAAC"};

strcmp( first,second);   // second compared to first, if positive then 1st is bigger

printf("%d",strcmp(first,second));

} 
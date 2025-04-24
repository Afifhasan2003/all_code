#include<stdio.h>

#include<string.h>

int fact(int n);
int main() {

//char new[]={"new world"};
char new[40];                      //if we didnt put any value in new thats oke too
char old[]={"old world"};


strcpy( new,old);   // the value of old is replacing the value of new

puts(new);
//puts(old);
printf("%s", old);
} 
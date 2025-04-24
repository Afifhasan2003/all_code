#include<stdio.h>

int main() {
char day;
printf("Enter day:");
scanf("%c",&day);

switch (day){
case 'a' : printf(" saturday");
break;
case 'b' : printf("sunday");
break;
case 'c': printf("monday");
break;
case 'd': printf("tuesday");
break;
case 'e': printf("wednesday");
break;
case 'f': printf("thursday");
break;
case 'g': printf("friday");
break;
default : printf("not a valid day");
}


return 0; 
    
}
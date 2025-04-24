#include<stdio.h>

float circle(float rad);         //here rad is the perameter (the variable where we put the value of argument)

int main() {

printf("area of circle is : %f",circle(5.0));  //here 5 is argument(the value that we are passing)
}

float circle(float rad) {
    return 3.1416* rad*rad;
}
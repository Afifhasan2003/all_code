#include<stdio.h>
#include<string.h>

typedef struct ComputerScienceEngineeringStudents {
    char name[100];
    int roll;
    float cgpa;
}cs;    // here cs will be considered as a nickname of ComputerScienceEngineeringStudents 

int main() {

        cs s1;
        strcpy(s1.name, "Afif");
        s1.roll=30; 
        s1.cgpa=4.00;
 
        cs s2;
        strcpy(s2.name,"sakib");
        s2.roll=40;
        s2.cgpa=3.99;

        printf(" first student's name is %s \n",s1.name);
        printf(" second student's name is %s \n ", s2.name);
}
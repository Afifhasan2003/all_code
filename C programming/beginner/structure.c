#include<stdio.h>
#include<string.h>

struct student
{
    int roll;
    float cgpa;
    char name[100];
};

int main() {

    struct student s1;
    s1.cgpa=4.00;
    s1.roll=162;
    //s1.name="afif";    //you can not directly do this 
 
    strcpy(s1.name,"Afif");    

    printf("roll is %d \n", s1.roll);
    printf("CGPA is %f \n", s1.cgpa);
    printf("name is %s \n",s1.name);
    
}
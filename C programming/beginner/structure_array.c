#include<stdio.h>
#include<string.h>

struct student
{
    char name[100];
    int roll;
    float cgpa;
};

int main(){

    // struct student cse[100];
    // cse[0].roll=20;
    // strcpy(cse[0].name, "Afif");                 // multiple line
    // cse[0].cgpa=3.45;

    struct student cse[100]={ " Afif", 20, 3.45};    //one line 
    
    printf("name is %s \n", cse[0].name);
    printf("roll is %d \n", cse[0].roll);
    printf("cgpa is %.2f \n", cse[0].cgpa);
}
#include<stdio.h>
#include<string.h>

struct student
{
    char name[100];
    int roll;
    float cgpa;
};

void info(struct student s1);

int main(){

    

    struct student s1={ " Afif", 20, 3.45}; 
    
    info(s1);
}

void info(struct student s1) {

    printf("name is %s \n", s1.name);
    printf("roll is %d \n", s1.roll);
    printf("cgpa is %.2f \n", s1.cgpa);
}
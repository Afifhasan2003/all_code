#include<stdio.h>
#include<string.h>

struct student
{
    char name[100];
    int roll;
    float cgpa;
};

int main(){


    struct student s1={ " Afif", 20, 3.45};    
    // struct student *ptr;
    // ptr=&s1;  (OR)

    struct student *ptr=&s1;
    
    printf("name is %s \n", (*ptr).name);     //with *ptr
    printf("roll is %d \n", ptr->roll);         // with ptr-> (this is prefered)
    printf("cgpa is %.2f \n", ptr->cgpa);
}
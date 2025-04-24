//we will pass struction in function

#include<stdio.h>
#include<string.h>

//void student(struct info *emp); //this wont work ,, we must place the structure before function.. coz we 
                                //are calling the struction inside the function
                                
struct info
{
    char name[40];
    int roll;
    float point;
};

void student(struct info emp);
int main() {

      struct info s1={"afif", 162, 3.8};

      student(s1);
    
    printf("after change roll is main:%d",s1.roll);    //this value will not change, and remain 162
    
 
return 0;
}
void student(struct info emp){

    printf("1st students name is %s \n", emp.name);
    printf("1st students name is %d \n", emp.roll);
    printf("1st students name is %f \n", emp.point);

     emp.roll=200;

    printf("after change roll is function: %d \n", emp.roll);

}
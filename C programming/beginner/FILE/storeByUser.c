#include<stdio.h>

int main(){

FILE *stn;
stn= fopen("student.txt", "w");

char name[100];
int roll;
float cgpa;

printf("Enter name:");
scanf("%s",name);
printf("Enter roll:");
scanf("%d",&roll);
printf("Enter CGPA:");
scanf("%f",&cgpa);

fprintf(stn, " Name is : %s \n",name);
fprintf(stn, " roll is : %d \n",roll);
fprintf(stn, " CGPA is : %.2f \n",cgpa);


fclose(stn);

}
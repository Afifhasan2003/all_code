#include<stdio.h>

void afifdata();
void himidata();
int main() {
   char who;
   printf("who's intro? --");
   scanf("%c",&who);
   if (who=='a')
   {
      afifdata();
   } else if (who=='h') {
      himidata();
   } else {
      printf("Dont know the person");
   }
   
 return 0;
}

void afifdata() {
   printf("my name is afif \n");
   printf("im a university student \n");
   printf("currently learning Coding \n \n \n");
   himidata();
}

void himidata(){
   printf("my name is himi \n");
   printf("i passed university \n");
   printf("im preparing for BCS exam \n \n \n");
}
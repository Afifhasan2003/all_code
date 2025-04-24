#include<stdio.h>


int main(){

FILE *odd;
odd=fopen("store_odd_number.txt","w");

int a;
printf("Enter a=");
scanf("%d", &a);

for (int i = 0; i <=a ; i++)
{
    if (i %2 !=0)
    {
        fprintf(odd, "%d \t", i);
      
    }
    
}

fclose(odd);

}
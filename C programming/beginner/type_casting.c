#include<stdio.h>
int main() {

    int a,b,c;
    float avg;
    printf("Enter a,b,c;");
    scanf("%d %d %d", &a,&b,&c);

    //avg=(a+b+c)/3;  // this is a mistake.cause (a+b+c) is a integar, and integar devided by another integer
                    // will return a integar value

    avg=(float)(a+b+c)/3;  //so type cast  

    printf("Average is %f",avg);
    
         
 
 
return 0;
}
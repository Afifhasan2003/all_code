#include<stdio.h>

void table(int n);
int main() {
    int n;

    table(n);
} 

void table(int n) {
    printf("Enter number:");
    scanf("%d",&n);
    for(int i=1; i<=10;i++){
        printf("%d \n",i*n);
    }
}
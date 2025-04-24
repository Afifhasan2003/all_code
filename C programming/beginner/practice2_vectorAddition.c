#include<stdio.h>

struct vector{
    int x;
    int y;
};

void addition(struct vector v1, struct vector v2, struct vector sum);
int main(){


 //first we need to create 3 vectors
    struct vector v1={3,5};
    struct vector v2={ 10,5};
    struct vector sum={ 0}; // vector sum is  0i+0j  at the  beginning
 
    addition(v1,v2,sum);
}

void addition( struct vector v1, struct vector v2, struct vector sum){

     sum.x=v1.x + v2.x;
     sum.y=v1.y + v2.y;

     printf("R = %d i + %d j", sum.x, sum.y);

}
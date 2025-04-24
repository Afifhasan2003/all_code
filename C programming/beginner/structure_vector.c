#include<stdio.h>

typedef struct vector{

    int x;
    int y;

} vec;

struct vector addition( vec v1,vec v2);
int main() {

      vec v1,v2,sum;

      v1.x=5;
      v1.y=6;
      v2.x=10;
      v2.y=10;

    sum=addition(v1, v2);

    printf("after addition x= %d  \n after addition y= %d",sum.x, sum.y);
    
 
return 0;
}

//int addition( vec v1,vec v2){   //here return type is not integer.. return type is a vector.. 
                                  //"struct vector" is data type

struct vector addition( vec v1,vec v2){

    struct vector _sum;
    _sum.x= v1.x + v2.x;
    _sum.y=v1.y + v2.y;

    return _sum;
    
}
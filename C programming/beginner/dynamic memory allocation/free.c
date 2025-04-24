#include<stdio.h>
#include<stdlib.h>

int main() {
    float *ptr;
    ptr=(float*)malloc(5*sizeof(float));

    ptr[0]=1;
    ptr[1]=1;
    ptr[2]=2;
    ptr[3]=2;
    ptr[4]=3;
    
    for(int i=0; i<5; i++){

        printf(" Entered number was: %.2f \n",ptr[i]);     
    }

    free(ptr);

    ptr=(float*)malloc(2*sizeof(float));

    ptr[0]=7;
    ptr[1]=8;

    for (int i = 0; i < 2; i++)
    {
        printf(" after free ptr is %.3f \n",ptr[i]);
    }

    free(ptr);

    ptr=(float*)calloc(2,sizeof(float));

    ptr[0]=10;
    ptr[1]=12;

    for (int i = 0; i < 2; i++)
    {
        printf("again after free ptr is %.3f \n",ptr[i]);
    }
    

    free(ptr);
                            //but we can not do this.. meaning, can not redefine ptr as array..
    // float ptr[3];
    // ptr[0]=20;
    // ptr[1]=25;
    // ptr[2]=28;
    //             for (int i = 0; i < 3; i++)
    //             {
    //                 printf("4th time ptr is : %f \n",ptr[i]);
    //             }
                

}
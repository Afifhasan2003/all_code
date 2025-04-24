#include<stdio.h>
int main() {

     int marks[10] ;
     marks[0]=5;
     int *ptr;
    //  ptr= &marks[0];  OR,
     ptr=marks;     //marks = &marks[0]


    //  printf("mark[0]is equal to : %d",*ptr);
     
    //now we can access others values from array by increasing the value of pointer

    for (int i = 0; i < 5; i++)     //accessing by array
    {
        printf("marks are :");
        scanf("%d", &marks[i]);
        
    }


    for (int i = 0; i < 5; i++)             //accessing by pointer
    {
    //     printf("the mark of student %d is : %d \n",i, *ptr);
    // ptr++ ;                                                          //both are correct

            printf("the mark of student %d is : %d \n",i, *(ptr+i));
            
            


    }
    
    
 
return 0;
}
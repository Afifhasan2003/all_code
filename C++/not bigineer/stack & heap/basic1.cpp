#include<iostream>
using namespace std;


int main() {


     //soo,, stack is where we normally use as memory, and heap is what we want to use as memory. 
     //heap has some benefits
     // 


    int a=10;  //stored in stack

    int *p=new int();  //allocate memory in heap ..but not like we put p in heap.. p is now pointing a adress in heap

    *p=10; 



return 0;
}


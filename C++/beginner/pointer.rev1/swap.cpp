#include<iostream>
using namespace std;

void swapByValue(int a,int b);
void swapByReference(int *ptr1,int *ptr2);

int main() {


     int a=2,b=5;

    swapByValue(a,b);
    cout<<"after swap by value a,b = "<<a<<" and "<<b<<endl;

    swapByReference(&a ,&b);
    cout<<"after swap by Ref a,b = "<<a<<" and "<<b<<endl;     //working perfectly

return 0;
}

void swapByValue(int a,int b){
    int temp=a;
    a=b;
    b=temp;

    cout<<"inside swap by value a,b = "<< a<<" and "<<b<<endl;

}
void swapByReference(int *ptr1,int *ptr2){

    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    cout<<"inside swap by Ref a,b = "<<*ptr1<<" and "<<*ptr2<<endl;

}
#include<iostream>
using namespace std;

void setValue(int *ptr);
void getValue(int *ptr);
int main() {

    int *a=new int;
    
    setValue(a);
    getValue(a);

return 0;
}

void setValue(int *ptr){
    *ptr=10;
}
void getValue(int *ptr){
    cout<<"value of ptr "<<*ptr;
}
#include<iostream>
using namespace std;
int main() {


     int a=10;
     int *ptr;
     ptr=&a;

     cout<<ptr<<endl;  //address of a
     cout<<&a<<endl;   //this is also adress of a
     cout<<*ptr<<endl; //value at ptr(dereferencing ptr)

    char b='z';
    char *ptrr;
    ptrr=&b;

     cout<<ptrr;  // does not print adress, undefiened behaviour
    cout<<&b;   //this is also doesnt print adress of b
    
     cout << static_cast<void*>(ptrr) << endl;  //this prints adress
     
     cout<<*ptrr; //value at ptr(dereferencing ptr)

return 0;
}

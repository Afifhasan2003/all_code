#include<iostream>
using namespace std;

void funcA(int a){
    cout<<"a="<<a<<endl;
    a++;
    cout<<"a="<<a<<endl;
}
void funcB(int *ptr){
    cout<<*ptr<<endl;
     // *a++; not this
    *ptr=*ptr+1;
    cout<<*ptr<<endl;


}
int main() {


     int a=2,b=2;
     int *ptr=&b;

     
    funcA(a);

    cout<<"after function call, a="<<a<<endl;

    cout<<"Now lets see call by reference"<<endl;

    
   // funcB(&b);
    //or 
    
    funcB(ptr);
    cout<<"after function call, b="<<b<<endl;


return 0;
}
 
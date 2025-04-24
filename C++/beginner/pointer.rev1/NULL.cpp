#include<iostream>
using namespace std;





int main() {


     int a=10;
     int * ptr= &a;
     int * ptr2;
     int *ptr3=NULL; 

     cout<<&a<<endl;
     cout<<ptr<<endl;
     cout<<ptr2<<endl; //gurbage value
     cout<<ptr3<<endl;


return 0;
}
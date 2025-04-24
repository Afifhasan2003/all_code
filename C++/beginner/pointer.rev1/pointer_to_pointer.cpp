#include<iostream>
using namespace std;
int main() {


     int a=10;
     int *b=&a;
    //  int *c=&b; not right
     int **c=&b;
     int ***d=&c;


    cout<<a<<endl;
    cout<<*b<<endl;
    cout<<**c<<endl;
    cout<<***d<<endl;
return 0;
}

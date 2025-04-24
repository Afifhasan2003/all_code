#include<iostream>
using namespace std;
int main() {


     int n=10;          //n=10 =0 1 0 1 0

    int m= n | 1<<2 ;
    cout << m <<endl;   //n=14= 0 1 1 1 0  added 1 on 2nd position(actually 3rd position)


    int a= n | 1<<3;     //this wont change,, coz there is already a 1 on 3rd position, so no point of adding 1 with 1
    cout<<a<<endl;  

return 0;
}

#include<iostream>
using namespace std;


    void ref(int &b){  //pass by reference using alias
                        // here & is not adress
        cout<<"value of a= "<<b<<endl;
        b=b +10;
        cout<<"changed value of a= "<<b<<endl;
    }


int main() {


     int a=10;
     
     ref(a);
     cout<<"value of a= "<<a<<endl;


return 0;
}
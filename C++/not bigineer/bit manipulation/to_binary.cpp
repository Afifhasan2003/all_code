#include<iostream>
#include<bitset>
using namespace std;
int main() {

    int n=5;
    // int m=bitset<32>(n);

    cout<<bitset<20>(n)<<endl;

    string str=bitset<30>(n).to_string();
     
     cout<<str<<endl;

     int a=stoi(str);
     cout<<"binary of n is : "<<a<<endl;

return 0;
}

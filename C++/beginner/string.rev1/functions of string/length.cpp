#include<iostream>
#include<string>
using namespace std;
int main() {

    string s1="hehehe";

    cout<<s1.length()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.capacity()<<endl;  //last two can vary depanding on computers
    cout<<sizeof(s1)<<endl;


return 0;
}

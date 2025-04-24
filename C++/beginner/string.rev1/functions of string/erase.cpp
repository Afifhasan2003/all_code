#include<string>
#include<iostream>
using namespace std;
int main() {

    string str="abcdefghijklmnopqrstuvwxyz";

    str.erase(2,5);     //(starting index, how many to erase)

    cout<<str<<endl;

     


return 0;
}

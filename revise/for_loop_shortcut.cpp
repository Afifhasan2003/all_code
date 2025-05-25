#include<iostream>
using namespace std;





int main() {


     string str;cin>>str;

     for(char c:str){           //its more efficient
        cout<<c;
     }


return 0;
}
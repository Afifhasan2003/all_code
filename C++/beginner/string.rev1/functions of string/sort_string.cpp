#include<iostream>
#include<string>
#include<algorithm>  //for sorting function
using namespace std;
int main() {

    string s1="ba2sf9wenlki1sr";
    sort(s1.begin(),s1.end());

    cout<<s1<<endl;

    sort(s1.begin(),s1.end(),greater<int>());
    cout<<s1<<endl;

    sort(s1.begin(),s1.end(),less<int>());
    cout<<s1<<endl;


     


return 0;
}

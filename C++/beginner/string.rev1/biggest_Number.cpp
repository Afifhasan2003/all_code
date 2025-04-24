#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {

    string s1="5189451684894"; //make the biggest number out of these number
     
    sort(s1.begin(),s1.end());
    cout<<s1<<endl;

    sort(s1.begin(),s1.end(),greater<int>());
    cout<<s1<<endl;

    sort(s1.begin(),s1.end(),less<int>());
    cout<<s1<<endl;

return 0;
}

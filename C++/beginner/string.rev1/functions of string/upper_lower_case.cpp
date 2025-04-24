#include<iostream>
#include<string>
#include<algorithm>  //for transform
using namespace std;
void makeUpper(string s1);
void makeLower(string s1);
int main() {

    string s1="aFifHasAn";

    makeUpper(s1);
    makeLower(s1);
     
    transform(s1.begin(),s1.end(),s1.begin(), ::toupper);
            //(starting of string, ending of string, starting of upper case, what to do)
    cout<<s1<<endl;


    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    cout<<s1<<endl;

return 0;
}

void makeUpper(string s1){
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i]>='a' && s1[i]<='z')
        {
            s1[i] -=32;
            cout<<s1[i];
        } else cout<<s1[i];
        
    } cout<<endl;
    
}
void makeLower(string s1){
     for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i]>='A' && s1[i]<='Z')
        {
            s1[i] +=32;
            cout<<s1[i];
        } else cout<<s1[i];
        
    } cout<<endl;
}
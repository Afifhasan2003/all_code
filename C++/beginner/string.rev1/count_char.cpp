#include<iostream>
#include<string>
using namespace std;
int main() {

    string s="aabbccddeeefffff";

    int alpha[26]={0};
    
     for (int i = 0; i < s.size(); i++)
     {
        alpha[s[i]-'a']++;
     }
     
    int max=0;
    char ans='a';
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i]>max)
        {
            max=alpha[i];
            ans = i+'a';
        }
        
    }

        cout<<"most repeted alphabet was "<<ans<<endl;
        cout<<"It was repeted "<<max<<" times"<<endl;

return 0;
}

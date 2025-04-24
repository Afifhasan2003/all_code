#include<iostream>
#include<string>
using namespace std;

int hexToDec(string n);

int main(){
    string n;
    cout<<"Enter a string: ";cin>>n;

    cout<<"decimal value is: "<<hexToDec(n);
}

int hexToDec(string n){

    // int s=sizeof(n);
    int s=n.size();         //not sizeof() **caution
   int ans=0, r=1;
    for (int i =s-1; i >=0; i--)            //A15B7C  from last to fist 
    {
        if (n[i]>='0' && n[i]<='9')
        {
            ans =ans +(n[i]-'0')*r;
        }
        else if(n[i]>='A' && n[i]<='F'){
            ans=ans + (n[i]-'A'+10)*r;
        }
        r=r*16;
    }
    return ans;

}
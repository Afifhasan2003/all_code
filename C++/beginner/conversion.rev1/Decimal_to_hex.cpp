#include<iostream>
using namespace std;

string decToHex(int n);
string decToHex2(int n);

int main() {
    int n;
    cout<<"Enter decimal number: ";
    cin>>n;

cout<<"Hexadecimal value is: "<<decToHex(n)<<endl;
cout<<"Hexadecimal value is: "<<decToHex2(n)<<endl;         //not working

}
string decToHex(int n){
int r=1;
string ans="";

    while (r<=n)
    {
        r=r*16;
    }   r=r/16;

    while (r>0)
    {
       int num=n/r;

       if (num<=9)
       {
        ans=ans + to_string(num);
       }
      else
       {
        char c= 'A'+num-10;
        ans.push_back(c);
       }
       n=n- r*num;
       r=r/16;
    }
    return ans;
}

string decToHex2(int n){

    string ans="";
    int rem;
   while (n>0)
   {
     rem=n %16;      //not rem= n/ 16   coz then if n=15, rem=0
                        //                  now if n=15 , rem=15    and so on
    if (rem<=9)
    {
        // ans=ans+ to_string(rem);  this wont work coz they are not the same.. coz number will be reveresed
        ans= to_string(rem) + ans;
    }
    else{
        char c='A' +rem-10;
        ans=c + ans ;
       
    }
    n=n/16;
    
   }
   return ans;
}



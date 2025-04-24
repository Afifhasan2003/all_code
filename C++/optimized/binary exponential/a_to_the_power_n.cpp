#include<iostream>
using namespace std;



// time complexity O(log(n))

int main() {


     int a,n;cin>>a>>n;

     int bin=0,p=1;
     while (n >0)
     {
        bin = bin + n %2* p;
        p *=10;
        n /=2;
     }
    //  cout<<bin;
   long long int ans=1;
    while (bin>0)
    {
        if (bin % 2 !=0)
        {
            ans = ans * a;

        }
        bin /=10;
        a = a*a;
    }
     
     cout<<ans;


return 0;
}
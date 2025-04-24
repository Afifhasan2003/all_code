// check if a number is power of two    like= 2,4,8.16


#include<iostream>
using namespace std;
int main() {


     int n; 
     cin>>n;        //n= 16 = 1 0 0 0 0
                    //n-1=15= 0 1 1 1 1   right most 1 and the following will flip

    bool ans = n && !(n & (n-1));   //if n=2,4,8.... then n & (n-1) = zero (always)

    if (ans)
    {
        cout<<n<<" is power of 2"<<endl;
    } else cout<<n<<" is not power of 2"<<endl;
    


return 0;
}

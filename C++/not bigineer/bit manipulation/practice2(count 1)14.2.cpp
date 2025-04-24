//count number of 1 in a binary  (not in normal procedure)
// we will use the fact that if n=1,2,4,8... then n & n-1 =0 
#include<iostream>
using namespace std;
int main() {


     int n;
     cin>>n;            //n=7 =1 1 1
                        //n-1=6= 1 1 0
    int count=0;        
    while (n)
    {
        n=n & (n-1);      // n=n & (n-1)= 1 1 0 =6  
                            
        count++;
    }
    
    cout<<count;


return 0;
}

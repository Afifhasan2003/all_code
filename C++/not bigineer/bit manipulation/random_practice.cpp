//count number of 1 in a binary number

#include<iostream>
using namespace std;
int main() {


    int n;cin>>n;
    int count=0;

    while (n)
    {
      n=n & (n-1);
      count++;
    }
    
   cout<<count;

return 0;
}


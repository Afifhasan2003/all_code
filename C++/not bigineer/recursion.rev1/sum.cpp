//sum of positive numbers till n

#include<iostream>
using namespace std;


int sumfunc(int n){
    if (n==0)
    {
        return 0;   //base case
    }
    
    
    return n + sumfunc(n-1);
}

int sumfunc2(int n,int sum){        //parameterised
    if (n==0)
    {   
        return sum;
    }

   return sumfunc2(n-1,sum+n);      //sum will increase
    
}
int main() {


     int n;
     cin>>n;

    cout<<sumfunc(n)<<endl;
    cout<<sumfunc2(n,0)<<endl;

return 0;
}

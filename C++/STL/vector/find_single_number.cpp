//finding a number that does not repet

#include<iostream>
using namespace std;


#include<vector>


int main() {

    int n;cin>>n;
     vector<int> vec;
    for (int i = 0; i < n; i++)
    {   int temp;
        cin>>temp;
        vec.push_back(temp);
    }   
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=ans^vec[i];         //if we do XOR of all the numbers, ans will be the number that present one time
                                // n^n=0 ,, n^m= non zero
    }
    
    cout<<ans<<endl;


return 0;
}
#include<iostream>
using namespace std;


#include<vector>


int main() {


     vector<int> vec={1,2,3,4,5};
     
     for (int i = 0; i < vec.size()/2; i++)
     {
        int temp=vec[i];
        vec[i]=vec[vec.size()-i-1];
        vec[vec.size()-i-1]=temp;
     }
     
    for(int a:vec) {
        cout<<a<<" ";
    }

return 0;
}
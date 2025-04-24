//print all the numbers from one to hundred excepts 7x

#include<iostream>
using namespace std;

int main(){
//  #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif 

for (int  i = 0; i <=100; i++)
{
    if(i%7==0){
        continue;
    }
    cout<<i<<"\t";

}


}
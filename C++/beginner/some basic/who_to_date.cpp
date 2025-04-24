#include<iostream>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    #endif

    int money;

    // cout<<"How much money do u have ";
    // printf("how much money do you have \n");
    cin>>money;

    if (money>=5000)
    {
        cout<<"Go out with Roshni";
    } 
    else if (money<=5000 && money>=2000){
        cout<<"Go out with Neha";
    } 
    else if(money >0 && money<=2000) {
        cout<<"Go out with nam nam";
    }
    else 
    cout<<"Go out with friends";

    return 0;
}
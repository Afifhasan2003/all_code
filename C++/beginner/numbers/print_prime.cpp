#include<iostream>
using namespace std;

int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int n;
    cout<<"Enter number: ";
    cin>>n;

    for (int i = 2; i < n; i++)
    {       
        int j;
            for (j= 2; j < i; j++)  //be careful
            {
                if (i%j ==0)
                {
                    break;
                }
                
            }
            if (j==i)
            {
                cout<<i<< "\t";
            }
            
    }
   
    return 0;
    

}
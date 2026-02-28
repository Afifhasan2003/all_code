#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& bills) {

    int five=0, ten=0,twen=0;
    for(auto a:bills){
        if(a==5)
            five++;
        else if (a==10 && five!=0)
        {
            ten++;
            five--;
        }
        else if (a==10 && five==0)
        {
            return false;
        }
        
        else if (a==20)
        {
            
            if(ten>0 && five>0)
            {
                ten--;
                five--;
            }
            else if (five>2)
            {
                five-=3;
            }
            else 
                return false;
            
            
        }
    }

    return true;
}
int main() {
    
    vector<int> bills = {5,5,10,10,20};
    cout<<lemonadeChange(bills)<<endl;

    return 0;
}
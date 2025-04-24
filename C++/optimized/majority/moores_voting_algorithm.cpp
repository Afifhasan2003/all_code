//This algorithm is for finding the element thats there more than n/2 times.. means more than half

#include<iostream>
#include<vector>
using namespace std;





int main() {


      vector<int> arr={1,3,5,1,2,2,3,3,3,3,2,2,2,3,3,3,3};
        int ans=0,freq=0;
      for (int i = 0; i < arr.size(); i++)
      {
         if (freq==0 )
         {
            ans=arr[i];
         }
         if (arr[i]==ans)
         {
            freq++;                     //when majority elements come, no matter how much negetive freq was, it will become positive
         } else freq--;
         
         
      }

      cout<<ans;
      


return 0;
}
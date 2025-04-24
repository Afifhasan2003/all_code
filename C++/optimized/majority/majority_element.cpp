#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int bruteforce(vector<int> arr){
    int count=1,maxnum=INT_MIN, ans;
       for (int i = 0; i < arr.size(); i++)
       {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i]==arr[j])
            {
                count++;
            }
            
        } if (count>maxnum)
        {
            maxnum=(count,maxnum);
            ans=arr[i];
        }
        
        
       } 
       return ans;
       
}
int optimised(vector<int> arr ){

        int ans,count=1,maxnum=INT_MIN;
        sort(arr.begin(),arr.end());
        

        for (int i = 0; i < arr.size()-1; i++)
        {
            if (arr[i+1]==arr[i])
            {
                count++;
                // maxnum=max(maxnum,count);
            }else count=1;
            if (count>maxnum)
            {
                ans=arr[i];
                maxnum=count;
            }
            
            
        }
        return ans;
        

}



int main() {


       vector<int> arr={1,3,5,1,2,2,3,3,3,3,2,2,2};

       cout<<bruteforce(arr)<<endl;
       cout<<optimised(arr)<<endl;
    


return 0;
}
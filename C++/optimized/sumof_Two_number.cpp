#include<iostream>
#include<vector>
using namespace std;

vector<int> bruteForce(vector<int> nums,int target){
    vector<int> ans;
     for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[i]+nums[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
            
        }
        
    }
    return ans;

}

vector<int>  optimised(vector<int> nums,int target){
    int i=0,j=nums.size()-1;
    vector<int> ans;
    for (int k = 0; k < nums.size(); k++)
    {   
        if (nums[i]+nums[j]>target)
        {
            j--;
        }
        else if(nums[i]+nums[j]<target){
            i++;
        }
        else {
            ans.push_back(i);
            ans.push_back(j);
        }
        
    }
    return ans;
}



int main() {


    vector<int> nums={1,3,5,9};  //while sorted
    int target=14;
    vector<int> ans=bruteForce(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;                //time complexity n^2
    cout<<ans[0]<<" "<<ans[1]<<endl;                //time complexity n
    
   
    

return 0;
}
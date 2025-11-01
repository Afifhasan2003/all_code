//checking if there is a majority element (an element that appears n/2 or more times)

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    
    int count=0,n=nums.size(),el;
    for (int i = 0; i < n; i++)
    {
        if(count==0){
            count=1;
            el=nums[i];
        }

        else if(el == nums[i]) count++;
        else count--;
    }   
            //count goes up for consecutive same elements, and other elements will try to bring count down
            //the only servivor is in el ( the majority element (if exists))

    //check if el is actually the majority
    int countCheck=0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==el)
        countCheck++;
    }

    if(countCheck > n/2) return el;

    return -1;
    
    
}

int main() {
    

    return 0;
}
//some trick for vectors
#include<iostream>
#include<vector>
#include<algorithm> //for reverse function
using namespace std;



void reverseVector(vector<int> &vec){
  //using stl
    reverse(vec.begin(),vec.end());
    for(int a:vec) {
        cout<<a<<" ";
    }
}

void printVector(vector<int> &alpha){

        for(int a:alpha){
            cout<<a<<"\t";
        } cout<<endl;

      
}

void findUniqueElement(){
    vector<int> vec={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9}; // 10 is the number that does not repeat
    int ans=0;
    for(int i=0;i<vec.size();i++)
    {
        ans=ans^vec[i];         //if we do XOR of all the numbers, ans will be the number that present one time
                                // n^n=0 ,, n^m= non zero
    }
    cout<<ans<<endl;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // handle k > n
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int numberOfSpecificElement(vector<int> &nums,int target){
    int cnt = count(nums.begin(), nums.end(), target);
    return cnt;
}

void moveTargetToEnd(vector<int>& nums,int target) {
    
    stable_partition(nums.begin(), nums.end(), [target](int x) {        //lembda function
        return x != target;
    });

}

int maximumElement(vector<int> &nums){
    int maxElement = *max_element(nums.begin(), nums.end());
    return maxElement;
}
int leastElement(vector<int> &nums){
    int minElement = *min_element(nums.begin(), nums.end());
    return minElement;
} 



int main() {


     vector<int> vec={1,2,3,4,5,6,3,7,3,8,9};
        cout << "Maximum Element: " << maximumElement(vec) << endl;
        cout << "Minimum Element: " << leastElement(vec) << endl;

return 0;
}
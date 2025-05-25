//some trick for vectors
#include<iostream>
#include<vector>
using namespace std;


void reverseVector(vector<int> &vec){
    for (int i = 0; i < vec.size()/2; i++)
     {
        int temp=vec[i];
        vec[i]=vec[vec.size()-i-1];
        vec[vec.size()-i-1]=temp;
     }
     
    for(int a:vec) {
        cout<<a<<" ";
    }
}

void forLoop(vector<int> &alpha){   //4 types of for loops
  
         //1. normal
    for(int i=0; i<alpha.size(); i++){
        cout<<alpha[i]<<"\t";
    } cout<<endl;

         //2. for loop is used to iterate over the vector
    for(char a:alpha){
        cout<<a<<"\t";
    } cout<<endl;
          //3. using pointer
    for(vector<int>::iterator it=alpha.begin(); it!=alpha.end();  it++){  
        cout<<*it<<"\t";
    } cout<<endl;
          //it is a pointer to the first element of the vector 
          //alpha.end() is a pointer to the mermory after the last element of the vector

          //4. using auto keyword
    for(auto it=alpha.begin(); it!=alpha.end();  it++){
        cout<<*it<<"\t";
    } cout<<endl;
          //auto is a keyword that automatically deduces the type 
}

void findUniqueElement(vector<int> &vec){
    vector<int> vec={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9}; // 10 is the number that does not repeat
    int ans=0;
    for(int i=0;i<vec.size();i++)
    {
        ans=ans^vec[i];         //if we do XOR of all the numbers, ans will be the number that present one time
                                // n^n=0 ,, n^m= non zero
    }
    
    cout<<ans<<endl;
}



int main() {


     vector<int> vec={1,2,3,4,5};
        reverseVector(vec);
     


     

return 0;
}
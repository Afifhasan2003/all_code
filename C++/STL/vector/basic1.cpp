#include<iostream>
using namespace std;


#include<vector>


int main() {


     
vector<int> vec1;
// cout<<vec1[0]<<endl;             this wont print anything, coz there is nothing inside vector

vector<int> vec2={1,2,3};
cout<<vec2[1]<<endl;

vector<int> vec3(3,2);              //first 3 int will be 2
cout<<vec3[2];

return 0;
}
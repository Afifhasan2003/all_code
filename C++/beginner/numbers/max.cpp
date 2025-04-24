#include<iostream>
using namespace std;





int main() {


     int a,b,c;cin>>a>>b>>c;
     int maxofab=(a+b+abs(a-b))/2;
     int max= (c+maxofab + abs(c-maxofab))/2;
     cout<<max<<endl;


return 0;
}
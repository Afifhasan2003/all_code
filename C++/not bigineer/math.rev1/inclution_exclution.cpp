//how many numbers between 1 and 40 are divisible by 5 and 7? 

#include<iostream>
using namespace std;



int main() {


     int a=1, b=40, x=5, y=7;

     int c1=b/x;
     int c2=b/y;
     int c3=b/(x*y); //numbers that are divisible both by 5,7.. like 35

     int ans=c1+c2-c3;
     cout<<ans;


return 0;
}
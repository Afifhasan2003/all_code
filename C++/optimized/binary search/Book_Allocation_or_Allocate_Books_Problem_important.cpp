//https://www.youtube.com/watch?v=JRAByolWqhw&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=21

#include<iostream>
#include<algorithm>
using namespace std;

 bool isvalid(int arr[],int mid, int n, int m){


     int student=1, apple=0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i]>mid)
          {
               return false;
          }
          
          if (apple +arr[i] <= mid)
          {
               apple +=arr[i];
          }
          else{
               apple=arr[i];
               student++;
          }
          
     }
     return student<=m;
     
     






 }



int main() {


     int arr[]={2,1,3,4};     //in 4 box, there 2,1,3,4 apple

     int n=4, m=2;            //m= number of student we have give the apples to.. 
                              //boxes will be given contiguously
                         //in best judgement, maximum number of apple a student will get? 


     if (n<m)
     {
          cout<<"invalid";
     }
     




     int st= *max_element(arr,arr+n) ;
     int end=0;        //st and end will be the range of probability
     for (int i = 0; i < n; i++)
     {
          end=end+arr[i];          //highest possible number of apple
     }

     int ans;
     while (st<=end)
     {
          int mid=st + (end-st)/2;

          if (isvalid(arr,mid,n,m))
          {
               end=mid-1;
               ans=mid;
          }
          else{
               st=mid+1;
          }
          

          
     }
     

     cout<<ans<<endl;





     
return 0;
}
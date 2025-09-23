#include <iostream>
#include<iomanip>           //must for setprecision
 using namespace std;

 void set_precision(){
    double R,A,n=3.14159;
    cin>>R;
    cout<<fixed<<setprecision(10)<<"A="<<n*(R*R)<<endl;
 }

 void checkPrime(){
    int a;
    cout<<"Enter number: ";
    cin>>a;
    int i;
    for (i =2; i < a; i++){
        if (a %i ==0)
        {
            cout<<a<<"is not prime";
            break;
        }
        
    }

    if(i==a){
        cout<<a<<"is prime";
    }
 }

 void printPrime(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    for (int i = 2; i < n; i++)
    {       
        int j;
            for (j= 2; j < i; j++)  //be careful
            {
                if (i%j ==0)
                {
                    break;
                }
                
            }
            if (j==i)
            {
                cout<<i<< "\t";
            }
            
    }
 }

 int get_max(){
    int a,b,c;cin>>a>>b>>c;
     int maxofab=(a+b+abs(a-b))/2;
     int max= (c+maxofab + abs(c-maxofab))/2;
     cout<<max<<endl;
     return max;
 }

 void printFibunaccy(){
        int n;cin>>n;
        int t1=0,t2=1,tn;
        for (int i = 0; i < n; i++)
        {
            cout<<t1<<"\t";
            tn=t1+t2;
            t1=t2;
            t2=tn;
          //return;  //absoutely no,, then funtion would stop after just one rotation
        }
        return;
    }

bool check(int a,int b ,int c){
    int q,r;
    int p=max(a, max(b,c));

    if (p==a)
    {
        q=b;
        r=c;
    }
    else if (p==b)
    {
        q=a;
        r=c;   
    } else {
        q=a;
        r=b;
    }
    
    if (p*p==q*q + r*r)
    {
        return true;
    }   
    else return false;

}

void incrementExample(){
    int a=10,b; 
    //b=a++;  here b will be 10
    //b=++a;  here b will be 11 after increament

        //10    12
    b=    a++ + ++a; 
    cout<<"b="<<b;
}



int main() {
 
   
    return 0;
}
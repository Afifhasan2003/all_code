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

int GCDbyrecursion(int a,int b){
    if (b==0)
    {
        return a;
    }
    return GCDbyrecursion(b,a%b);
}
int GCDBySubstract(int a, int b){
    
    while (a!=b)
    {                                          // a=12,b=8
     if (a>b)                                     
     {                                          //a=12-8=4
        a=a-b;                                 // b=8-4
     }else b=b-a;
        
    }
    return a;
}
int GCDByModulo(int a, int b){
    while (b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}


bool howManyisDevidedByBoth(int n,int x,int y){
    // int a=1, b=40, x=5, y=7;

     int c1=n/x;
     int c2=n/y;
     int c3=n/(x*y); //numbers that are divisible both by 5,7.. like 35

     int ans=c1+c2-c3;
     cout<<ans;

}



int main() {

   int a,b;
   cin>>a>>b;
   cout<<"GCD by Recursion: "<<GCDbyrecursion(a,b)<<endl;
   cout<<"GCD by Substraction: "<<GCDBySubstract(a,b)<<endl;
   cout<<"GCD by Modulo: "<<GCDByModulo(a,b)<<endl;

    return 0;
}
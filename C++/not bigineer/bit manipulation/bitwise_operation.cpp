#include<iostream>
using namespace std;

void leftshift() {
    int n=5;        //n=5=0101     : a<<b means a*2^b (2 to the power b)               
    int a=n<<2;     // a=20=010100
    cout<<a<<endl;  // 20 

    int m=1<<2;            //1=1
                           //m<<2=0100     
    cout<<m<<endl;  // 4
}
void rightshift() {
    int b=20;                   //b=20=010100
    int c=b>>2;                //c=5=0101
    cout<<c<<endl;  // 5

    
                                //17=10001
    int d=17>>2;               //d=4=0100
    cout<<d<<endl;  // 4
}

bool getBit_ON_position(int n,int pos ){
    // is there 1 or 0 at the given position in binary representation of n
    // 9 = 1001 here pos = 0 is 1(rightmost position)

    return (n & (1<<pos))!=0;
}

int clearBit(int n, int pos){
    int mask=~(1<<pos);         //    1<<1 = 00010
    return (n & mask);          //   ~(1<<1) = 11101 
}

int updateBit(int n, int pos, int value){
                                        //ofcourse value is either 0 or 1
    int mask=~(1<<pos);  // ~ does 1's complement,  so mask = 1111 1011 if pos=2
    n=n & mask;                    //first step: clear bit at that position
    return n | (value<<pos);       //second step: set bit at that position 
}

bool isPowerOf2(int n){
    return (n && !(n & (n-1)));   //if n=2,4,8.... then n & (n-1) = zero (always)
                                 //16 = 10000
                                //15 = 01111
                        
}

int count_1_inBinary(int n){
    int count=0;
    while(n){
        n=n & (n-1);      // n=n & (n-1)= 1 1 0 =6  
                            
        count++;
    }               //say n =7 =111 ,n-1 =6=110
                    //n=6=110  //n-1=5=101 
                    //n=4=100  //n-1=3=011
                    //n=0=000  //n-1=2=010
                    //each time it removes the last set bit
    return count;
}

int findUnique(int arr[],int n){
    int xorsum=0;           //starting from 0 wont be problem , as 0^X = X
    for (int  i = 0; i < n; i++)
    {
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}


int main() {
    

    cout<<"there is "<<getBit_ON_position(5,2)<<" at position 2 in 5"<<endl;

    cout<< updateBit(11,2,1)<<endl;             //11= 0 1 0 1 1
                                                //15=0 1 1 1 1

return 0;
}

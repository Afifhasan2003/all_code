//to clear a 1 from binary number 

#include<iostream>
using namespace std;

int clearBit(int n, int pos);
int main() {


    cout<<clearBit(11, 1)<<endl;        //11 = 0 1 0 1 1 
                                        //9 = 0 1 0 0 1

return 0;
}

int clearBit(int n, int pos){
    int mask=~(1<<pos);         //    1<<1 = 00010
    return (n & mask);          //   ~(1<<1) = 11101 
}
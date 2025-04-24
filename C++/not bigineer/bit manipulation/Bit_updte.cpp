//file name update_bit.cpp
//god knows why i can not use it as the actual file name
#include<iostream>
using namespace std;

int updateBit(int n, int pos, int value);
int main() {


        cout<< updateBit(11,2,1)<<endl;             //11= 0 1 0 1 1
                                                    //15=0 1 1 1 1


return 0;
}

int updateBit(int n, int pos, int value){

    int mask=~(1<<pos);
    n=n & mask;                    //first step: clear bit at that position
    return n | (value<<pos);       //second step: set bit at that position 
}
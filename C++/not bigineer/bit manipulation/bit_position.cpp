#include<iostream>
using namespace std;

int getbit(int n,int pos);

int main() {


    cout<<getbit(5,1);   // 5=  0   1   0   1
                          //    3   2   1   0   <- these are position

return 0;
}

int getbit(int n,int pos){

    return (n & (1<<pos))!=0;
}
/*In C++, all numbers, whether written in decimal, binary, or any other base, are stored in binary format 
internally. When you perform bitwise operations like & (bitwise AND) or << (left shift), they operate on 
the binary representations of these numbers.*/
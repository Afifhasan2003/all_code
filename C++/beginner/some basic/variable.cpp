#include<iostream>
using namespace std;

int main(){
    int a=2;
    float b=4;
    char c='g';
    bool d=1;
    
    //type modifier 

    long int e;
    short int f;
    signed int g;
    unsigned int h =5;  //we can not input negetive number here.. i mean compiler wont understand negetive number

   

    cout<<"size of int :"<<sizeof(int)<<endl;
    cout<<"size of fload :"<<sizeof(float)<<endl;
    cout<<"size of char :"<<sizeof(char)<<endl;
    cout<<"size of bool :"<<sizeof(bool)<<endl;
    cout<<"size of long int :"<<sizeof(long int)<<endl;
    cout<<"size of short int :"<<sizeof(short int)<<endl;
    cout<<"size of signed int :"<<sizeof(signed int)<<endl;
    cout<<"size of unsigned int :"<<sizeof(unsigned int)<<endl;

}
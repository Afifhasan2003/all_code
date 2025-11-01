#include<iostream>
using namespace std;

int fact(int a){

    int fact=1;
    for (int i = 1; i <=a; i++)
    {
        fact=fact*i;
    }
    return fact;
}
int nCr(int n, int r){
    if (r > n) return 0;
    int nCr=fact(n)/(fact(n-r) * fact(r));
    return nCr;
}

int fibunaccy(int n){
    if (n==0)
    {
        return 0;
    } else if (n==1)
    {
        return 1;
    }


    return fibunaccy(n-1)+ fibunaccy(n-2);
}
int power(int a, int n){
    if (a==0)
    {
        return 1;       //base case
    }
    
    return n*power((a-1),n);
}

int main(){
    int n,r;
    

    

}


//not working with big values
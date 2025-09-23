#include<iostream>
#include <cstring>  //need this for using strlen
using namespace std;

bool isPalindrome(char arr[]) {
    int n = strlen(arr);
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char arr[100];
    cin >> arr;


   

    

    return 0;
}

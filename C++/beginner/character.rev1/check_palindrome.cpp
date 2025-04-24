#include<iostream>
#include <cstring>  //need this for using strlen
using namespace std;
int main() {


     char arr[100];
     cin>>arr;

    //  int n=sizeof(arr);
    //  cout<<n;

    int n=strlen(arr);
    

    bool check=1;

    for (int i = 0; i < n/2; i++)
    {
        if (arr[i] != arr[n-1-i])
        {
            check= false;
            break;
        }
    }
    if (check==1)
    {
        cout<<"word is palindrome";
    }
    else cout<<" word is not palindrome";

return 0;
}

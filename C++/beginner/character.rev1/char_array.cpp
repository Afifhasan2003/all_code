#include<iostream>
using namespace std;

void iterate_String(char arr[]){
    int i=0;
    while (arr[i]!= '\0')
    {
        cout<<arr[i]<<endl;
        i++;
    }
    
}
int main() {


     char arr[6]={"apple"};  //number of array has to be one bigger that the number of character we input
                            // cause there will be a '\o ' added automatically


    iterate_String(arr);


return 0;
}

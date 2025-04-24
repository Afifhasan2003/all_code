#include<iostream>
using namespace std;
int main() {


     char arr[6]={"apple"};  //number of array has to be one bigger that the number of character we input
                            // cause there will be a '\o ' added automatically


    int i=0;
    while (arr[i]!= '\0')
    {
        cout<<arr[i]<<endl;
        i++;
    }
    
     


return 0;
}

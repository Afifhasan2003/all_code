#include<iostream>
#include<string>
using namespace std;
int main() {

    string s1="asfnauifvhewauihfeufhiuretvqyehfhsdfjfsdjfahoir32yr734vvjfiqeituhvfjcnvnvnndksdkjfqocomputerietqupioetubefwjqiorev";
     
    //in that string, there is a word "computer"

    cout<<s1.find("compu")<<endl;  //the starting index (index of C will be printed)


    for (int i = 84; i <= 91; i++)
    {
        cout<<s1[i];
    }
    
return 0;
}

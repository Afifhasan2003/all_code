#include<iostream>
#include<string>
using namespace std;

int main(){

    // char sentence[100];

    // cin.getline(sentence,100);

                                //BOTH WORKS
                                
    string sentence;   //***this will require #include<string>***

    getline(cin,sentence);


    cout<<sentence;

}
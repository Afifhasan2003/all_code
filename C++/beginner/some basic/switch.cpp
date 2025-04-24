#include<iostream>
#include<string>
using namespace std;

 main() {

    // string name;   switch does not take string
     //                it only takes integer or character   
    // cin>>name;

    // char name[20];


    char name;
    cout<<"Enter first word ";
    cin>>name;

    switch (name)
    {
    case 'a':
        cout<<"his name is Afif \n";
        cout<<"his age is 18 \n";
        cout<<"his is varsity student \n";
        break;
    case 'b':
        cout<<"his name is babu \n";
        cout<<"his age is 17 \n";
        cout<<"his is collage student \n";
        break;
    
    default: 
        cout<<"dont know him";
        break;
    }



}
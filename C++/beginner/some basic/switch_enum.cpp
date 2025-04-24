#include<iostream>
#include<cstring>
using namespace std;

enum boy{afif,babu};

int main(){
    // string person;
    char person[20];
    cin>>person;

   //boy name=person;  can not do this directly 


     boy name;
    // if (person == "afif") {          we should not campare string directly with another word
    //     name = afif;
    // } else if (person =="babu") {
    //     name = babu;

    

     if (strcmp(person, "afif") == 0) {
        name = afif;
    } else if (strcmp(person, "babu") == 0) {
        name = babu;



    } else {
        cout << "Invalid name." << endl;
    }

    // char name;
    //cout<<"Enter first word ";
    //cin>>name;

    switch (name)
    {
    case afif:
        cout<<"his name is Afif \n";
        cout<<"his age is 18 \n";
        cout<<"his is varsity student \n";
        break;
    case babu:
        cout<<"his name is babu \n";
        cout<<"his age is 17 \n";
        cout<<"his is collage student \n";
        break;
    
    default: 
        cout<<"dont know him";
        break;
    }




}
#include<iostream>
using namespace std;

int main(){

    char line[20];
    // cin>>line;     this can not take multiple line
    

    // scanf("%s",&line); //It doesnt work for multiple line


    fgets(line,20,stdin);  // it works fine

    


     printf("%s",line); //HERE both works 
    // cout<<line;


}
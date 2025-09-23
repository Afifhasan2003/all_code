#include<iostream>
using namespace std;
#include<string>
#include<algorithm>    //for sort

void appendStrings(string str1, string str2) {
    string s1="afif";
    string s2=" hasan";
    
   
    cout<<s1 + s2<<endl;

    //or 

    string s3=s1+s2;
    cout<<s3<<endl;

     //or
    
    s1.append(s2);
    cout<<s1<<endl;
}

void clearString(){
    string str="afif hasan";
    cout<<str<<endl;

    str.clear();
    cout<<str<<endl;  //wont print anything,, just to be clear if we dont asign anything is a variable, 
                        //there will be still something
}

bool compareString(string str1, string str2) {
    

    if(str1.compare(str2)==0){
        cout<<"Strings are equal"<<endl;
        return true;
    }
    else if (str1.compare(str2) < 0)
    {
        cout << "String 1 is less than String 2" << endl; // lexicographical comparison
        return false;
    }
    else {
        cout << "String 1 is greater than String 2" << endl;
        return false;
    }
}

bool checkEmpty(string str) {
    if(str.empty()){
        cout<<"String is empty"<<endl;
        return true;
    }
    else{
        cout<<"String is not empty"<<endl;
        return false;
    }
}

void eraseFromString() {
    string str="abcdefghijklmnopqrstuvwxyz";
    cout<<str<<endl;

    str.erase(2,5);     //(starting index, how many to erase)
    cout<<str<<endl;    //abfghijklmnopqrstuvwxyz
}

void findInString(){
    string s1="asfnauifvhewauihfeufhiuretvqyehfhsdfjfsdjfahoir32yr734vvjfiqeituhvfjcnvnvnndksdkjfqocomputerietqupioetubefwjqiorev";
    
    int startIndex=s1.find("computer");

    cout<<"Starting index is : "<<startIndex<<endl;

        for (int i = startIndex; i < startIndex + 8; i++)
            cout<<s1[i];
        cout<<endl;
        //OR
        
        string subStr=s1.substr(startIndex,8); //(starting index, length of substring)
        cout<<subStr<<endl;
}

void insertInString() {
    string s1="abcdefghijklmnopqrst";
    s1.insert(2,"hehehe");      //(starting index, string to insert)
    cout<<s1<<endl;
}

int String_To_Integer(string str) {
    int num=stoi(str);   //string to integer
    return num;
}

string Integer_To_String(int num) {
    return to_string(num);
}

void sizeAndCapacity() {
    string s1="afif hasan";
    cout<<"Size: "<<s1.size()<<endl;            //size
    cout<<"Length: "<<s1.length()<<endl;     //length
    cout<<"Capacity: "<<s1.capacity()<<endl;   //capacity
    cout<<"Size of string object: "<<sizeof(s1)<<endl;      //size of string object

    s1.resize(6);      //resize
    cout<<"After resize: "<<s1<<endl;

    
}

void sortString() {
    string s1="ba2sf9wenlki1sr";
    sort(s1.begin(),s1.end());
    
    cout<<s1<<endl;

    sort(s1.begin(),s1.end(),greater<int>());
    cout<<s1<<endl;

    sort(s1.begin(),s1.end(),less<int>());
    cout<<s1<<endl;
}

void reverseString() {
    string s1="afif hasan";
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;
}

void toLowerCase() {
    string s1="AfIf HaSaN";
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    cout<<s1<<endl;
}

void toUpperCase() {
    string s1="AfIf HaSaN";
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    cout<<s1<<endl;
}

void subString() {
    string s1="heheheheafifhehehe";
    string s2=s1.substr(8,4);    //(starting index,how many)
    cout<<s2<<endl;
}



int main() {

    sizeAndCapacity();

    return 0;
}

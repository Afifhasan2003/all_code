#include<iostream>
#include<vector>
using namespace std;



void eraseElementFromVector() {
    //Erace element
    vector<char> alpha2={'a','b','c','d','e','f','g','h'};

    alpha2.erase(alpha2.begin()+1);     //{'a','c','d','e','f','g','h'}  2nd element is removed

    alpha2.erase(alpha2.begin()+1,alpha2.begin()+3); //{a,'e','f','g','h'}  end is not removed
    for(char x:alpha2){
        cout<<x<<" ";
    }cout<<endl;

}

void insertElementInVector() {
    //Insert element
    vector<char> alpha2={'a','b','c','d','e','f','g','h'};
    alpha2.insert(alpha2.begin()+1,'x'); //{'a','x','b','c','d','e','f','g','h'}
    

    alpha2.insert(alpha2.begin()+1,3,'y'); //{'a','y','y','y','b','c','d','e','f','g','h'}
    for(char x:alpha2){
        cout<<x<<" ";
    }cout<<endl;

}

void insertVectorInVector() {
    //Insert vector in vector
    vector<int> vec1={1,2,3,4,5};
    vector<int> vec2={6,7,8,9,10};
    vec1.insert(vec1.begin()+2,vec2.begin()+1,vec2.end()); //{1 2 7 8 9 10 3 4 5 }
    for(int x:vec1){
        cout<<x<<" ";
    }cout<<endl;
}
int main() {

    vector<int> vec1;
    vector<int> vec2={1,2,3}; //{1,2,3} 
    vector<int> vec3(3,2);     //{2,2,2} 3 times 2

    vector<int> veccpy(vec2); //now veccpy={1,2,3}
    vec2.swap(vec3); //now vec2={2,2,2} and vec3={1,2,3}

    veccpy.clear(); //clears the vector, size will be 0 

    bool isEmpty = vec1.empty(); //0 means not empty, 1 means empty
    

    vector<char> alpha={'a','b','c','d'};
    cout<<"size of alpha "<<alpha.size()<<endl;

    alpha.push_back('e'); 
    alpha.emplace_back('f'); //same but better performance  {a,b,c,d,e,f}


    cout<<"size after pushback "<<alpha.size()<<endl;       //size will be 6
    cout<<"capacity after pushback "<<alpha.capacity()<<endl;   //capacity will be 8, 
    for(char x:alpha){
        cout<<x<<" ";
    }cout<<endl;

    alpha.pop_back(); //removes last element
    cout<<"size after popback "<<alpha.size()<<endl;    //size will be 5
    for(char x:alpha){
        cout<<x<<" ";
    }cout<<endl;

    cout<<"front= "<<alpha.front()<<endl;
    cout<<"back= "<<alpha.back()<<endl;



    

    vec1.swap(vec2); //now vec1={1,2,3} and vec2={6,7,8,9,10}
    

return 0;
}
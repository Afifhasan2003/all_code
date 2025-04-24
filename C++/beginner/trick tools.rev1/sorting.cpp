#include<iostream>
using namespace std;

void swap_sorting(int n, int num[]);
void insert_sorting(int n, int num[]);
int main() {

    int n;
    cout<<"How many numbers: "; cin>>n;
    int num[n];
    cout<<"Enter unsorted numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }

    swap_sorting(n,num);
    // insert_sorting(n,num);


return 0;
}
void swap_sorting(int n, int num[]){
        for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            // if (num[i]<num[j])  //descending
            if (num[i]>num[j])     //ascending
            {
                int temp=num[j];
                num[j]=num[i];
                num[i]=temp;
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<"\t";
    }
}
void insert_sorting(int n, int num[]){

    for (int  i = 1; i <n; i++)    {
        int current=num[i];
        int j=i-1;
        while (num[j]>current && j>=0)
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=current;
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }
    
    
}
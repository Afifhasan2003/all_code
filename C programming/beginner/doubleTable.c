#include<stdio.h>

void storeTable( int arr[][10] , int n, int m,int number);   //we must declare the 2nd dimention of array
int main() {

    int table[2][10]; //arr[n][m]

    storeTable(table ,0, 10, 2);
    storeTable(table, 1,10,3); 

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", table[0][i]);
    }
    
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t ",table[1][i]);
    }
    


}

void storeTable(int arr[][10], int n, int m ,int number) {

    for (int  i = 0; i < m ; i++)
    {
        arr[n][i]=number * (i+1);   //dont use i++ here .. because using it here causes unexpecter behaviour as 
                                    //as i++ is already used once in the loop.. 
    }
    
}
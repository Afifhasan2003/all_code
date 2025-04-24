//Enter five people's address

#include<stdio.h>
#include<string.h>

struct address {
    int houseNo;
    int roadNo;
    char area[100];
    char city[100];
};

void printAdd(struct address add);

int main(){
    struct address add[5];

    for (int i = 0; i < 5; i++)
    {
    printf("Enter address of %d th person \n", i+1);
    printf("House no: ");
    scanf("%d",&add[i].houseNo);
    printf(" Enter road no:");
    scanf("%d", &add[i].roadNo);
    printf(" Enter area:");
    scanf("%s", add[i].area);
    printf(" Enter city:");
    scanf("%s", add[i].city);

    }
    

        printAdd(add[0]);
        printAdd(add[1]);
        printAdd(add[2]);
        printAdd(add[3]);
        printAdd(add[4]);


}

void printAdd(struct address add){
    printf("Address is : %d, %d, %s, %s, \n", add.houseNo , add.roadNo , add.area, add.city );


}
//add->houseNo, add->roadNo, add->area, add->city
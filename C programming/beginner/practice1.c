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

    printf("Enter address of 1st person \n");
    printf("House no: ");
    scanf("%d",&add[0].houseNo);
    printf(" Enter road no:");
    scanf("%d", &add[0].roadNo);
    printf(" Enter area:");
    scanf("%s", add[0].area);
    printf(" Enter city:");
    scanf("%s", add[0].city);


    printf("Enter address of 2nd person \n");
    printf("House no: ");
    scanf("%d",&add[1].houseNo);
    printf("Enter road no:");
    scanf("%d", &add[1].roadNo);
    printf("Enter area:");
    scanf("%s", add[1].area);
    printf("Enter city:");
    scanf("%s", add[1].city);


    printf("Enter address of 3rd person \n");
    printf("House no: ");
    scanf("%d",&add[2].houseNo);
    printf("Enter road no:");
    scanf("%d", &add[2].roadNo);
    printf("Enter area:");
    scanf("%s", add[2].area);
    printf("Enter city:");
    scanf("%s", add[2].city);


    printf("Enter address of 4th person \n");
    printf("House no: ");
    scanf("%d",&add[3].houseNo);
    printf("Enter road no:");
    scanf("%d", &add[3].roadNo);
    printf("Enter area:");
    scanf("%s", add[3].area);
    printf("Enter city:");
    scanf("%s", add[3].city);


    printf("Enter address of 5th person \n");
    printf("House no: ");
    scanf("%d",&add[4].houseNo);
    printf("Enter road no:");
    scanf("%d", &add[4].roadNo);
    printf("Enter area:");
    scanf("%s", add[4].area);
    printf("Enter city:");
    scanf("%s", add[4].city);




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
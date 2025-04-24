#include<stdio.h>

struct date{

    int date;
    int month;
    int year;

};

int compare( struct date d1, struct date d2);
int main() {

     struct date d1={12,02,2002};
     struct date d2={31,07,2003};

    int a =compare(d1, d2);
    
    if (a==1)
    {
        printf("1st date came after 2nd date ");
        
    } else if(a== -1){
        printf("2nd date came after 1st date");
    }
    else{
        printf("two dates are same");
        
    }
 
return 0;
}
int compare( struct date d1, struct date d2){

    if (d1.year>d2.year)
    {
        return 1;
    }
    if (d1.year<d2.year)
    {  
        return -1;
    }
    if (d1.month>d2.month)
    {
        return 1;   
    }
    if (d1.month<d2.month)
    {
        return -1;
    }
    if (d1.date>d2.date)
    {
        return 1;
    }
    if (d1.date<d2.date)
    {
        return -1;
    }
    return 0;
}


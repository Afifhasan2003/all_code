 #include<stdio.h>

 void printString(char arr[]);
 int main(){

    //char name[]={'A', 'F', 'I','F', '\0'};
   //char name[]=" AFIF";                           // all three are fine.. differennce is that one we 
                                             //we put string in array, we can not change it,, but if we put if 
                                             //we put inside a pointer, then we can change it(overwrite it)
   char *name= "AFIF";
    //printf("name is %s", name);

    printString (name); 

 }

 void printString( char arr[]) {

    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c \t",arr[i]);
    }
    printf(" \n");
 }
//read whole paragraph

#include<stdio.h>

int main(){
    FILE *check;
    check=fopen("paragraph.txt", "r");


     if (check == NULL) {
        printf("File not found or cannot be opened.");
        return 1; // Exit with error code
    }

    char ch;
    ch=fgetc(check);
    
    while (ch != EOF)
    {
        printf("%c",ch);
        ch=fgetc(check);        //when you use fgetc() to read a character from a file, the file pointer
                                // automatically advances to the next character after each read operation.
    }
    printf("\n THE END");

    fclose(check); // Close the file after reading

    return 0;

}
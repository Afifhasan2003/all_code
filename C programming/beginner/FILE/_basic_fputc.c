#include<stdio.h>

int main(){

    FILE *fptr;
    fptr=fopen("write.txt", "w");
    
    
    // fprintf(fptr,"%c",'s');
    // fprintf(fptr,"%c",'a');
    // fprintf(fptr,"%c",'k');
    // fprintf(fptr,"%c",'i');
    // fprintf(fptr,"%c",'b');
                                                    
    fputc('s',fptr);       //character by character
    fputc('a',fptr);
    fputc('k',fptr);
    fputc('i',fptr);
    fputc('b',fptr);
   
    fclose(fptr);

}
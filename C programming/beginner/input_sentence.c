#include<stdio.h>

int main() {
                                    //here user will input any sentence
    char sentence[100];
    printf("Enter any sentence:");
    fgets(sentence,100,stdin);

    printf("Entered sentence is : %s", sentence);
}



// int main() {
                                                        //here sentence is given already
//     char sentence[]="my name is afif";
//     printf("Entered sentence is :%s", sentence);
// }
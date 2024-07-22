#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

void formatString(char* source, char* d){

    int j = 0;
    for(int i = 0; source[i] != '\0'; i++){
        if( isalpha(source[i])){
            d[j++] = tolower(source[i]);
        }
    }

    d[j] = '\0';
}


bool isPalindrome(char* string){
    int len = strlen(string);
    for(int i = 0; i < len / 2; i++){
        if(string[i] != string[len - i -1]){
            return false;
        }
    }
    return true;

}

int main()
{

    char string[SIZE];
    char newstring[SIZE];

    printf("Please enter a string: ");
    if(fgets(string, SIZE, stdin) != NULL){
        size_t len = strlen(string);
        if(len > 0 && string[len - 1] == '\n'){
            string[len - 1] = '\0';
        }
        formatString(string,newstring);

        if(isPalindrome(newstring)){
            printf("True");
        }
        else{
            printf("False");
        }}
    else{
    printf("Error...");
    return 1;
    }


    return 0;
}

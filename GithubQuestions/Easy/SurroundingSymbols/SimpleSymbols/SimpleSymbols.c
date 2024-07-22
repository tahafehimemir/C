#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 100


bool SimpleSymbol(char* string){
/*c'de direkt boolean olmadýgý için kütüphanesini cagýrdým. */
    int len = strlen(string);

    for(int i = 0; i < len; i++){
        if(isalpha(string[i])){
            if(i == 0 || i == len -1 ||string[i - 1] != '+' || string[i + 1] != '+'){
                return false;
                /*ilk karakter son karakter ve saðda solda + olacak sorgusu yaptým */
            }
        }
    }
    return true;
}




int main()
{
    char string[SIZE];
    size_t len = 0;

    printf("Enter a string please: ");

    if(fgets(string, SIZE, stdin) != NULL){
        len = strlen(string);
        if(len > 0 && string[len - 1] == '\n'){
            string[len - 1] = '\0';
        }
    if(SimpleSymbol(string)){
        printf("This recommendation is true.\n");
    } else{
        printf("This recommendation is false.\n");

    }
    }
    else{
        printf("Error...\n");
        return 1;
    }

    return 0;
}

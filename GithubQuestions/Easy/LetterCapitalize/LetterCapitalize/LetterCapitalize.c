#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

void letterCapitalize(char* string){

    int flag = 0;
/* burada bir flag belirledim c�mlenin bitiminde miyim yoksa
i�inde miyim kontrol� i�in. */
    for(int i = 0; string[i] != '\0'; i++){
        if(isspace(string[i])){
            flag = 0;
            /*bo�luk karakterinde d��ar�day�m. */
        }
        else{
            if(flag == 0){
                string[i] = toupper(string[i]);
                flag = 1;
                /*kelimenin ilk harfini toupper ile b�y�tt�m. */
            }
        }
    }


}




int main()
{
    char string[SIZE];
    size_t len = 0;
    printf("Please enter a string: ");

    if(fgets(string, SIZE, stdin) != NULL){
        len = strlen(string);
        if(len > 0 && string[len - 1] == '\n'){
            string[len - 1] = '\0';
            /*sona geldik mi kontrol� ve bo�luk karakter de�i�imi */
        }
        letterCapitalize(string);
        printf("Your string is: %s", string);
    }
    else{
        printf("Error...");
        return 1;
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100


void changingLetters(char* string){
    for(int i = 0; string[i] != '\0'; i++){

        if(isalpha(string[i])){
                /* alfabenin herhangi bir harfi mi diye bakýyoruz. */
            if(string[i] == 'z'){
                string[i] = 'a';
        /* burada z ise a a ise z atamasý kontrolü yapýyoruz */
            }
            else if(string[i] == 'Z'){
                string[i] = 'A';
            }
            else {
                string[i]++;
                /* burada bir sonraki harfe geçiþ yapýyoruz. */
            }
        }

        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            string[i] = toupper(string[i]);
            /* sesli harfleri toupper fonksiyonuyla büyük harfe çeviriyoruz. */
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
            /* stringi fgets ile alýyorum boþ deðilse uzunluðunu alýp ardýndan boþluk karakterini kontrol ediyorum.
            boþluk karakterini bitiþ karakteriyle deðiþtiriyorum. */
        }
    changingLetters(string);

    printf("Your new string: %s\n", string);

    }
    else{
        printf("Error..\n");
        return 1;
        /* hatalý durumda return 1 ile çýkýþ yapýyorum. */
    }

    return 0;
}

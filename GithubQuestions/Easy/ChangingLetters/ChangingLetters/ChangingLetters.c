#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100


void changingLetters(char* string){
    for(int i = 0; string[i] != '\0'; i++){

        if(isalpha(string[i])){
                /* alfabenin herhangi bir harfi mi diye bak�yoruz. */
            if(string[i] == 'z'){
                string[i] = 'a';
        /* burada z ise a a ise z atamas� kontrol� yap�yoruz */
            }
            else if(string[i] == 'Z'){
                string[i] = 'A';
            }
            else {
                string[i]++;
                /* burada bir sonraki harfe ge�i� yap�yoruz. */
            }
        }

        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            string[i] = toupper(string[i]);
            /* sesli harfleri toupper fonksiyonuyla b�y�k harfe �eviriyoruz. */
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
            /* stringi fgets ile al�yorum bo� de�ilse uzunlu�unu al�p ard�ndan bo�luk karakterini kontrol ediyorum.
            bo�luk karakterini biti� karakteriyle de�i�tiriyorum. */
        }
    changingLetters(string);

    printf("Your new string: %s\n", string);

    }
    else{
        printf("Error..\n");
        return 1;
        /* hatal� durumda return 1 ile ��k�� yap�yorum. */
    }

    return 0;
}

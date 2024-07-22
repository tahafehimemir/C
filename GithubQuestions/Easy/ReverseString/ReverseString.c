#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void reverse(char* string, size_t len){
    int i;
    for(int i = 0; i < len/2 ; i++){
        /*Bir kelimenin yar�s�n� al�p di�er yar�s�yla
        yer de�i�tirmek reverse i�lemini sa�lar. */
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    /* burada basit temp y�ntemini kulland�m. */
    }

}



int main()
{
    char string[SIZE];
    size_t len = 0;

    printf("Enter a string please: ");

    if(fgets(string, SIZE, stdin) != NULL){
            /*fgets fonksiyonunu kulland�m scanf
            fonksiyonu birden fazla kelimeyi alm�yordu.

            fgetsin NULL de�er verip vermedi�inin kontrol�n�
            yap�yorum */

        len = strlen(string);

        if(len > 0 && string[len - 1] == '\n'){
            string[len - 1] = '\0';
            len--;
        }
        /*fgets fonksiyonu enter tu�u ile sona erer ve alt
        sat�ra ge�me komutu '\n' ekler sonuna bunun kontrol�n�
        yap�p do�ru bir �ekilde son bulmas� i�in '\0' ile de�i�tirdim.
        */

        reverse(string, len);
        printf("Reversed string: %s\n", string);

    }


    return 0;
}

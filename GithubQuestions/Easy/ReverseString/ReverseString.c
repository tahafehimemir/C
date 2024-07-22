#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void reverse(char* string, size_t len){
    int i;
    for(int i = 0; i < len/2 ; i++){
        /*Bir kelimenin yarýsýný alýp diðer yarýsýyla
        yer deðiþtirmek reverse iþlemini saðlar. */
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    /* burada basit temp yöntemini kullandým. */
    }

}



int main()
{
    char string[SIZE];
    size_t len = 0;

    printf("Enter a string please: ");

    if(fgets(string, SIZE, stdin) != NULL){
            /*fgets fonksiyonunu kullandým scanf
            fonksiyonu birden fazla kelimeyi almýyordu.

            fgetsin NULL deðer verip vermediðinin kontrolünü
            yapýyorum */

        len = strlen(string);

        if(len > 0 && string[len - 1] == '\n'){
            string[len - 1] = '\0';
            len--;
        }
        /*fgets fonksiyonu enter tuþu ile sona erer ve alt
        satýra geçme komutu '\n' ekler sonuna bunun kontrolünü
        yapýp doðru bir þekilde son bulmasý için '\0' ile deðiþtirdim.
        */

        reverse(string, len);
        printf("Reversed string: %s\n", string);

    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* isPrime(int* a){

    if(*a <= 1){
        return false;
    }
    for(int i = 2; i <= *a / 2; i++){
        if(*a % i == 0){
            return false;
            /*asallýk kavramý yarýsýna kadar olan sayýlara
            bölünememe üzerine oturtulabilir. */
        }
    }

    return true;

}





int main()
{
    int* number;
    printf("Enter the number please: ");
    scanf("%d",&number);

    if(isPrime(&number)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }




    return 0;
}

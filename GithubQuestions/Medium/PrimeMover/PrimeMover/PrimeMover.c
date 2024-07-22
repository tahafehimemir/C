#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

bool isPrime(int* a){

    if(*a <= 1){
        return false;
    }
    for(int i = 2; i*i <= *a; i++){
        if(*a %i == 0){
            return false;
        }
        /* asal kontrolü yaptým */
    }
    return true;


}

int* primeMover(int* a){
    int counter = 0;
    static int prime;
    int n = 2;

    while(counter < *a){
        if(isPrime(&n)){
            prime = n;
            counter++;
        }
        /* burada static belirledim pointerlarla çalýþtýðým için
        fonksiyon bitince gitmesini istemiyorum */
        /* verdiðim sayýya kadarki tüm deðerleri asal mý deðil mi kontrol
        ede ede gidiyor. Asalsa prime atýyor ve yeniden yeniden yapýyor bunu. */
        n++;
    }
    return &prime;

}




int main()
{   int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if(number < 1 || number > 10000){
        printf("Please enter a number between 1 and 10.000");
        return 1;
        /*soruda 10^4 kadar vermiþ. */
    }
    int* result = primeMover(&number);
    printf("The %dth prime number is %d\n",number, *result);

    return 0;
}

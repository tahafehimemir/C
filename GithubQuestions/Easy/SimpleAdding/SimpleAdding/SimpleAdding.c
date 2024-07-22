#include <stdio.h>
#include <stdlib.h>

int simpleAdding(int n){

    int sum = 0;

    for(int i = 0; i <= n; i++){

        sum +=i;
    }
    /* basit summation iþlemi yaptým verilen sayýya kadar */
    return sum;
}




int main()
{
    int number = 0;
    printf("Please enter number to add: ");
    scanf("%d",&number);

    printf("Addition of this number is: %d",simpleAdding(number));
    return 0;
}

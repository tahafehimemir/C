#include <stdio.h>
#include <stdlib.h>

int division(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main()
{

    int number1, number2, result;
    printf("Enter Number 1 and Number 2 please: ");
    scanf("%d %d", &number1, &number2);

    result = division(number1, number2);
    printf("The division of %d and %d is %d\n",number1, number2, result);
    return 0;
}

#include <stdio.h>

int factorial(int a) {
    int result = 1;
    if(a == 0 || a == 1){
        result = 1;
        /* 0 faktoriyel ve 1 faktoriyel 1 'dir.*/
    }
    else{
        for (int i = 2; i <= a; i++) {
        result *= i;
    }
        return result;
}
}

int main() {
    int num;

    printf("Enter a number to factorial please: ");
    scanf("%d", &num );


    if (num < 0) {
        printf("Can not be negative numbers.\n");
    } else {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }

    return 0;
}

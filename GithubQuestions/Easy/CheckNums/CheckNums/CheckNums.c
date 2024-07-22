#include <stdio.h>
#include <string.h>


char* CheckNums(int num1, int num2) {
    if (num2 > num1) {
        return "True";
    } else if (num2 < num1) {
        return "False";
    } else {
        return "-1";
    }
}

int main() {
    int num1, num2;
    printf("Enter Number 1: ");
    scanf("%d", &num1);
    printf("Enter Number 2: ");
    scanf("%d", &num2);

    printf("Result: %s\n", CheckNums(num1, num2));

    return 0;
}

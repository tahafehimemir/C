#include <stdio.h>
#include <string.h>
#include <math.h>

int BinaryConverter(char* string) {
    int d = 0;
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        if (string[i] == '1') {
            d += pow(2, len - 1 - i);
        }
    }

    return d;
}

int main() {
    char* binary1 = "100101";
    char* binary2 = "011";

    printf("%s -> %d\n", binary1, BinaryConverter(binary1));
    printf("%s -> %d\n", binary2, BinaryConverter(binary2));

    return 0;
}

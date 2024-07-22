#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

bool StringScramble(char* string1,char* string2) {
    int count[SIZE];

    for (int i = 0; string1[i] != '\0'; i++) {
        count[(char)string1[i]]++;
    }

    for (int i = 0; string2[i] != '\0'; i++) {
        if (count[(char)string2[i]] == 0) {
            return false; //
        }
        count[(char)string2[i]]--;
    }

    return true;
}

int main() {
    char string1[SIZE], string2[SIZE];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    if (StringScramble(string1, string2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int SimpleMode(int arr[], int n) {
    int maxCount = 0;
    int mode = -1;
    int otherMode = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
            otherMode = 1;
        }
        else if (count == maxCount && arr[i] != mode) {
            otherMode = 1;
        }
    }

    if (otherMode && maxCount > 1) {
        return mode;
    } else {
        return -1;
    }
}

int main() {
    int arr1[] = {5, 5, 2, 2, 1};
    int arr2[] = {3, 4, 1, 6, 10};

    printf("[5, 5, 2, 2, 1]: %d\n", SimpleMode(arr1, sizeof(arr1)/sizeof(arr1[0])));
    printf("[3, 4, 1, 6, 10]: %d\n", SimpleMode(arr2, sizeof(arr2)/sizeof(arr2[0])));
    return 0;
}

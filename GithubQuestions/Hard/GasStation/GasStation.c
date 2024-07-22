#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void gcMaker(const char* station, int* gas, int* cost) {
    int i = 0;
    *gas = 0;
    *cost = 0;

    /*istenilen g:c format�n� sa�lamaya �al���yorum */


    while (station[i] != ':' && station[i] != '\0') {
        *gas = *gas * 10 + (station[i] - '0');
        i++;
        /* : 'den �nceki k�s�m gas */
    }

    if (station[i] == ':') {
        i++;
    }

    while (station[i] != '\0') {
        *cost = *cost * 10 + (station[i] - '0');
        i++;
        /* :'dan sonraki k�s�m cost */
    }
}

char* gasStation(char** strArr, int size) {
    int totalGas = 0, totalCost = 0, currentGas = 0;
    int startIndex = 0;


    for (int i = 1; i < size; i++) {
        int gas, cost;
        gcMaker(strArr[i], &gas, &cost);

        totalGas += gas;
        totalCost += cost;

        currentGas += gas - cost;

        if (currentGas < 0) {
            startIndex = i;
            currentGas = 0;
            /* gas negatif olursa burdan ��kamay�z */
        }
    }

    if (totalGas >= totalCost) {
        printf("%d\n", startIndex);
        /*ba�lang�c noktas� */
        return NULL;
        /* ba�ar�l� oldugunda bir �ey d�nd�rme */
    } else {
        /*tamamlanamaz */
        return "impossible";
    }
}

int main() {
    char* input1[] = {"4", "1:1", "2:2", "1:2", "0:1"};
    char* input2[] = {"4", "0:1", "2:2", "1:2", "3:1"};

    if (gasStation(input1, 5) == NULL) {
        printf("input1: impossible\n");
    }
    if (gasStation(input2, 5) == NULL) {
        printf("input2: \n");
    }

    return 0;
}

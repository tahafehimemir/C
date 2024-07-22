#include <stdio.h>
#include <stdlib.h>

char* ArithGeo(int array[], int size){

    if(size < 2){
        return "-1";
    }


    int difference = array[1] - array[0];
    int isArithmetic = 1;
    int isGeometric = 1;

    for(int i = 2; i < size; i++){
        if(array[i] - array[i - 1] != difference){
            isArithmetic = 0;
            break;
        }
    }

    if(array[0] != 0 && array[1] % array[0] == 0){
        int geometricRatio = array[1] / array[0];
        for(int i = 2; i < size; i++){
            if(array[i - 1] == 0 ||array[i] / array[i - 1] != geometricRatio){
                isGeometric = 0;
                break;
            }
        }
    }
    else{
        isGeometric = 0;
    }
    if(isArithmetic){
        return "Arithmetic";
    } else if (isGeometric){
        return "Geometric";
    }
    else{
        return "-1";
    }

}



int main()
{
    int array1[] = {5,10,15};
    int array2[] = {2,4,16,24};
    int array3[] = {2,6,18,54};

    printf("Array 1: %s\n", ArithGeo(array1, sizeof(array1)/sizeof(array1[0])));
    printf("Array 2: %s\n", ArithGeo(array2, sizeof(array2)/sizeof(array2[0])));
    printf("Array 3: %s\n", ArithGeo(array3, sizeof(array3)/sizeof(array3[0])));
    /* sizeof(array1)/sizeof(array1[0] dizinin uzunluðu için bunu kullandým
                             genel byte'ý birim byte bölüyorum ve uzunluk buluyorum. */
    return 0;
}

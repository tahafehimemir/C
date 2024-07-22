#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/*HATALI */
int largestNumber(int array[], int size){

    int largest = array[0];
    for(int i = 1; i < size; i++){
        if(array[i] > largest){
            largest == array[i];
        }
    }

    return largest;
}

bool arrayAdditionCan(int array[], int size, int target, int index){

    if(target == 0){
        return true;
    }
    if(target < 0 || index >= size){
        return false;
    }

    return arrayAdditionCan(array, size, target - array[index], index +1) ||
            arrayAdditionCan(array, size, target, index +1);


}

char* arrayAddition(int array[], int size){

    int largest = largestNumber(array,size);

    int arrayRemain[size - 1];
    int index = 0;

    for(int i = 0; i < size; i++){
        if(array[i] != largest){
            arrayRemain[index++] = array[i];
        }
    }

    if(arrayAdditionCan(arrayRemain, size - 1, largest, 0)){
        return "True";

    }
    else{
        return "False";
    }

}








int main()
{
    int array1[] = {5, 7, 16, 1, 2};
    int array2[] = {3, 5, -1, 8, 12};

    printf("Array1: %s\n", arrayAddition(array1, sizeof(array1) / sizeof(array1[0])));
    printf("Array2: %s\n", arrayAddition(array2, sizeof(array2) / sizeof(array2[0])));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
void alphabetSoup(char* string){

    int len = strlen(string);
    char temp;

/* bubble sort kullanarak parçalýcam. */
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1; j++){
            if(string[j] > string[j + 1]){
                temp = string[j];
                string[j] = string[j+1];
                string[j+1] = temp;
            }
        }
    }

}


int main()
{
    char string[SIZE];

    printf("Enter a string please: ");
    scanf("%s", string);
    alphabetSoup(string);
    printf("Souped string: %s\n", string);


    return 0;
}

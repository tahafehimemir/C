#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void runLenght(char* string){
    int len = strlen(string);
    int counter = 1;

    for(int i = 0; i < len; i++){
        if(string[i] == string[i + 1]){
                counter++;
        }
        else{
            printf("%d%c", counter, string[i]);
            counter = 1;
        }
    }

    printf("\n");

}




int main()
{
    char string[SIZE];

    printf("Please enter a string: ");
    scanf("%s", string);

    runLenght(string);
    return 0;
}

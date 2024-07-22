#include <stdio.h>
#include <stdlib.h>

void timeConvert(int* a){

    int hour = *a/60;
    int minute = *a%60;

    printf("%d : %02d\n",hour,minute);

}

int main()
{
    int input = 0;
    printf("Please enter your input:");
    scanf("%d",&input);

    timeConvert(&input);
    return 0;
}

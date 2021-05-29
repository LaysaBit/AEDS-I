#include <stdio.h>
#include <string.h>
#include <stdlib.h>
                                //ALGORITMO SEM RECURSÃO.

void swap(char *a, char* b){
    char tmp = *a;
    char *q = &b;
    *a = *b;
    *b = tmp;
}
void reverse(char *array){
    int len = strlen(array);
    int middleIndex = len/2;

    if (i == middleIndex || len == 1)
        return 0;
    else{
        for(int i = 0; i<= mid; ++i)
            swap(&array[i], &array[--len]);
    }
}
int main () {
    char num[25];
    scanf("%s", num);
    
    swap(&num[0]); // swap(num) == swap(&num[0]);
    printf("%s\n", num);

    return 0;
}
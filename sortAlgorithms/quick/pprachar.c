#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                //Esse algoritmo não é bom o suficiente, visto que pode causar O(n²), já que usa pivot fixo no final/inicio.
void swap( char * a, char * b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(char *array, int start, int end){
    char pivot = array[end];
    int partitionIndex = start;

    for (int i = start; i < end; ++i)
        if(array[i] <= pivot)
            swap(&array[i],&array[partitionIndex++]);

    swap(&array[partitionIndex], &array[end]);
    return partitionIndex;
}
void quickSort(char *array, int start, int end){
    if( start < end){
        int partitionIndex = partition(array, start, end);
        quickSort(array, start, partitionIndex-1);
        quickSort(array, partitionIndex+1, end);
    }
}

int main (){
    char array[20];
    scanf("%s", array);

    quickSort(array, 0, 14);
    
    for (int i = 0; i < 15; ++i)
        printf("%c ", array[i]);
    printf("\n");
}
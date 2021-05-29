#include <stdio.h>
#include <stdlib.h>
                //Esse algoritmo não é bom o suficiente, visto que pode causar O(n²), já que usa pivot fixo no final/inicio.
void swap( int * a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int *array, int start, int end){
    int pivot = array[end];
    int partitionIndex = start;

    for (int i = start; i < end; ++i)
        if(array[i] <= pivot)
            swap(&array[i],&array[partitionIndex++]);

    swap(&array[partitionIndex], &array[end]);
    return partitionIndex;
}
void quickSort(int *array, int start, int end){
    if( start < end){
        int partitionIndex = partition(array, start, end);
        quickSort(array, start, partitionIndex-1);
        quickSort(array, partitionIndex+1, end);
    }
}

int main (){
    int array[]={7,2,1,6,8,5,3,4};
   
    quickSort(array, 0, 7);
    
    for (int i = 0; i <= 7; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch( int key, int * array, int sup, int inf) {
    int middle = (sup+inf)/2;
    
    if(inf <= sup){
        if(key == array[middle])
            return middle;
        else{
            if(key < array[middle]){
                sup = middle-1;
                return binarySearch( key, array, sup, inf);
            }
            if(key > array[middle]){
                inf = middle+1;
                return binarySearch(key, array, sup, inf);
            }
        }
    }
    return -1;
}
int main(){
    int n, key;
    scanf("%d %d", &n, &key);

    int * array = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);
    
    int length = sizeof(array);
    int result = binarySearch(key, array, length, 0); 

    if(result == -1)
        printf("Elemento não encontrado!\n");
    else
        printf("Elemento encontrado na posição %d do vetor.\n", result);
    
    free(array);
    return 0;
}
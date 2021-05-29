#include <stdio.h>
#include <stdlib.h>

int shellSort(int * array, int n){
    for (int gap = n/2; gap > 0; gap/=2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = array[i]; //variavel auxiliar.

            int j;
            for (j = i; ( (j>= gap) && (array[j-gap] > temp) ) ; j-= gap)
                array[j] = array[j-gap]; //compares elements which are distance apart 'gap'.
            
            array[j] = temp;
        }
    }
    return 0;
}

int main (){
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a,int *b){
    a^=b;
    b^=a;
    a^=b;
}
void selectionSort(int * v) {

	for (int i = 0; i < v.length; i++) {
		int i_menor = i;
		
		int a = ( sizeof(v)/sizeof(v[0]) );
		for (int j = i + 1; j < a; j++)
			if (v[j] < v[i_menor])
				i_menor = j;
		
		swap(&v[i], &v[i_menor]);
	}
}
int main (){
    		

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void insertionMinHeap(int *a, int n, int value){
    ++n;
    a[n] = value;
    int i = n;

    while(i > 0){
        int parent = i/2;
        if( a[i] < a[parent]){
            swap(&a[parent], &a[i]);
            i = parent;
        }
        else
            return;
        
    }
}
void heapify(int *a, int heapsize, int i){
    int smallest;
    int l = 2*i;
    int r = 2*i+1;

    if ( ( l<=heapsize ) && ( a[l] < a[i]) )
        smallest = l;
    else
        smallest = i;
    
    if ( ( r<=heapsize ) && ( a[r] < a[smallest]) )
        smallest = r;
    
    if(smallest != i){
            printf("O parent node é: %d, o menor child node é: %d,\n", a[i], a[smallest] );
            swap(&a[i], &a[smallest]);  // é nessa operação que o menor número vai para o parent node.
            
            printf("Depois de ter trocado o menor node com o parent node: ");
            for (int j = 0; j < heapsize; ++j) // talvez eu precise passar a variavel n para a função.
                printf("%d ", a[j]);           // em vez do heapsize.
            printf("\n");
            
            heapify(a, heapsize, smallest); // aqui é analisado se os nodes filhos estão ordenados
    }                                       // isto é, os nodes filhos possuem chaves menores que o
}                                           // parent node. Esse processo é repetido até chegar no node 
void buildMinHeap(int *a, int heapsize){    // que não possui descendentes.
    int i;
    for (i = heapsize/2; i > 0; --i)
        heapify(a, heapsize, i);
}
void heapSort(int *a, int heapsize){
    int i;

    buildMinHeap(a, heapsize);    
    
    for (i = heapsize; i>1; --i) // Deletando chave.
    {
        swap(&a[i], &a[1]);
        heapsize--;
        heapify(a, heapsize, 1);
    }
}
int main (){
    int n;
    scanf("%d", &n);
    int *ptr = malloc( n*sizeof(int) );
    
    srand(time(0));
    for (int i = 0; i < n; ++i){
        ptr[i] = rand()%100;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    heapSort(ptr,n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    
    printf("\n");
    
    free(ptr);
    return 0;
}
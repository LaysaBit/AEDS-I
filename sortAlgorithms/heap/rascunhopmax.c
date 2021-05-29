#include <stdio.h>
#include <stdlib.h>
#include <time.h>

printa(int *a, int lastIndex){
    for (int i = 1; i <= lastIndex; ++i)
        printf("%d ", a[i]);
    printf("\n\n");
}

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void maxHeapify(int *a, int heapsize, int i, int priority, int res, int lastIndex){ 
    int largest;
    int l = 2*i;
    int r = 2*i+1;

    if ( ( l<=heapsize ) && ( a[l] > a[i] ) )
        largest = l;
    else
        largest = i;
        
    if ( ( r<=heapsize ) && ( a[r] > a[largest]) )
        largest = r;
        
    if(largest != i){
        if(res == 4){
            printf("    Organizando o node %d e seus descendentes:\n", i);
            printf("        Indice maior node children: %d; Indice parent node: %d.\n", largest, i);
        }
        swap(&a[i], &a[largest]);

        if (res == 4){ 
            printf("        Trocou-se o maior node children com o parent node:\n            ");
            printa(a, lastIndex);
        }
    
        maxHeapify(a, heapsize, largest, priority, res, lastIndex);
    }
    else{
        if(res == 4){
            printf("    Node %d já está ordenado com seus descendentes.\n        ", i);
            printa(a, lastIndex);
        }
    }
}
void minHeapify(int *a, int heapsize, int i, int priority, int res, int lastIndex){
    int smallest;
    int l = 2*i;
    int r = 2*i+1;

    if ( ( l<=heapsize ) && ( a[l] < a[i] ) )
        smallest = l;
    else
        smallest = i;
        
    if ( ( r<=heapsize ) && ( a[r] < a[smallest]) )
        smallest = r;
        
    if(smallest != i){
        if(res == 4){
            printf("    Organizando o node %d e seus descendentes:\n", i);
            printf("        Indice de menor node children: %d; Indice parent node: %d.\n", smallest, i);
        }
                
        swap(&a[i], &a[smallest]);
                
        if(res == 4){
            printf("        Trocou-se o menor node children com o parent node:\n            ");
            printa(a, lastIndex);
        }

        minHeapify(a, heapsize, smallest, priority, res, lastIndex);
    }
    else{
        if(res==4){ 
            printf("    Node %d já está ordenado com seus descendentes.\n        ", i);
            printa(a, lastIndex);
        }
    }
}
void insertionHeap(int *a, int length, int value, int priority, int res){
    length+=1;
    a[length] = value;
    int i = length;

    while(i > 0){
        int parent = i/2;
        printf("\nParent: %d\n", parent);

        if(priority == 1){     //para max heap
            if( a[i] > a[parent]){
                //printf("Antes do swap do %d child e %d parent:", a[i], a[parent]);
                //printa(a,length);

                swap(&a[parent], &a[i]);
                i = parent;

                printa(a,length);
            }
            else 
                return;
        }
        if(priority == 2){     //para min heap
            if( a[i] < a[parent]){
                swap(&a[parent], &a[i]);
                i = parent;
            }
            else 
                return;
        }
    }
}
void buildHeap(int *a, int heapsize, int priority, int res, int lastIndex){
    int i;
    for (i = heapsize/2; i > 0; --i){ 
        if(priority == 1)
            maxHeapify(a, heapsize, i, priority, res, lastIndex);
        if(priority == 2)
            minHeapify(a, heapsize, i, priority, res, lastIndex);
    }
}
void heapSort(int *a, int heapsize, int priority, int res){
    int i;
    int lastIndex = heapsize;

    if (res == 4)   
        printf("\nCriando a Max Heap:\n");
    
    buildHeap(a, heapsize, priority, res, lastIndex);    
    
    if (res == 4){
        printf("\nMax Heap feita:\n");
        printa(a, lastIndex);
        
        printf("Começando a ordenação do vetor:\n");
    }
    /* um for para ordenação crescente do heap.
    for (i = heapsize; i>1; --i) // Mostrar essa parte no print.
    {
        swap(&a[i], &a[1]);
        heapsize--;
        if(priority == 1)
            maxHeapify(a, heapsize, 1, priority, res, lastIndex);
        if(priority == 2)
            minHeapify(a, heapsize, 1, priority, res, lastIndex);
    }*/
}
int main (){
    printf("Qual o tamanho do Heap que vai ser criado?\n");
    int tamanho;
    
    scanf("%d", &tamanho);
    
    int *ptr = malloc(tamanho*sizeof(int) );
    
    srand(time(0));
    for (int i = 1; i <= tamanho; ++i)
        ptr[i] = rand()%100;
        
    printf("\nEscolha uma das opções abaixo:\n");
    printf("(1) Criar o heap de máximo\n");
    printf("(2) Criar o heap de mínimo\n");
    
    int priority;
    scanf("%d", &priority);
    
    int res;
    printf("\nEscolha uma das opções abaixo:\n");
    printf("(3) Você deseja visualizar apenas o resultado do heap de máximo?\n");
    printf("(4) Mostrar os passos da ordenação do heap.\n");
    printf("(5) Inserir um novo elemento no heap, já existente, e mostrar o heap. Insira o valor do novo elemento\n"); //No momento estou criando esse.
    printf("(6) Remover um elemento do heap. É necessário informar o índice do elemento.\n");
    printf("(7) Alterar a prioridade de um elemento do heap. É necessario informar o índice do elemento.\n");
        
    scanf("%d", &res);

    if(res==3){
        heapSort(ptr,tamanho, priority, res);
        
        printf("\nVetor ordenado:\n");
        printa(ptr, tamanho);
    }
        
    if(res==4){
        printf("\n\nVetor não ordenado:\n");
        printa(ptr, tamanho);
            
        heapSort(ptr,tamanho, priority, res);
            
        printf("\nVetor ordenado:\n");
        printa(ptr, tamanho);
    }
    if(res==5){
        int value;
        scanf("%d", &value);

        heapSort(ptr,tamanho, priority, res);
        
        printf("\nHeap já existente:\n");
        printa(ptr, tamanho);
        
        insertionHeap(ptr, tamanho, value, priority, res);

        printf("\nNovo max-heap:\n");
        printa(ptr, tamanho+1);
    }

    free(ptr);
    return 0;
}
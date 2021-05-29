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
void maxHeapify(int *a, int heapsize, int i, int priority, int lastIndex, int aux){ 
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
        if ( aux == 1) {
            printf("Organizando o node %d e seus descendentes:\n", i);
            printf("Indice maior node children: %d; Indice parent node: %d.\n", largest, i);
        }
        swap(&a[i], &a[largest]);

        if (aux == 1) { 
            printf("Trocou-se o maior node children com o parent node:\n            ");
            printa(a, lastIndex);
        }
    
        maxHeapify(a, heapsize, largest, priority, lastIndex, aux);
    }
    else{
        if (aux == 1) {
            printf("Node %d já está ordenado com seus descendentes.\n        ", i);
            printa(a, lastIndex);
        }
    }
}
void minHeapify(int *a, int heapsize, int i, int priority, int lastIndex, int aux){
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
        if (aux == 1) {
            printf("    Organizando o node %d e seus descendentes:\n", i);
            printf("        Indice de menor node children: %d; Indice parent node: %d.\n", smallest, i);
        }
                
        swap(&a[i], &a[smallest]);
                
        if (aux == 1) {
            printf("        Trocou-se o menor node children com o parent node:\n            ");
            printa(a, lastIndex);
        }

        minHeapify(a, heapsize, smallest, priority, lastIndex, aux);
    }
    else{
        if (aux == 1) { 
            printf("    Node %d já está ordenado com seus descendentes.\n        ", i);
            printa(a, lastIndex);
        }
    }
}
void decreaseKey(int *a, int key, int index, int length, int priority, int aux){
    a[index] = key;
    
    if( priority == 1) // para max heap
       maxHeapify(a, length, index, priority, length, aux);
    if(priority == 2)  // para min heap
    {   
        int i = index;
        while(i != 1)
        {
            int parent = i/2;
            if(aux == 1)    printf("\nParent: %d\n", parent);
            if( a[i] < a[parent]){
                if(aux == 1)  printf("Child %d é menor que o parent %d\n", i, parent);

                swap(&a[parent], &a[i]);

                if(aux==1){
                    printf("Vetor depois do swap entre o parent %d e o child %d:\n", parent, i);
                    printa(a,length);
                }

                i = parent;
            }
            else 
                return;
        }
    }
}
void increaseKey(int *a, int key, int index, int length, int priority, int aux){
   a[index]= key;

   if( priority == 1) // para max heap
   {
        int i = index;
        while(i != 1)
        {
            int parent = i/2;
            if(aux==1)  printf("\nParent:%d\n", parent);

            if( a[i] > a[parent]){
            if(aux==1)  printf("Child %d é maior que o parent %d\n", i, parent);

            swap(&a[parent], &a[i]);
            
            if(aux==1){
                printf("Vetor depois do swap entre o parent %d e o child %d:\n", parent, i);
                printa(a,length);
            }

            i = parent;
            }
            else 
                return;
        }
   }
   if(priority == 2) // para min heap
       minHeapify(a, length, index, priority, length, aux);
}
void insertionHeap(int *a, int length, int value, int priority, int aux){
    length+=1;
    a[length] = value;
    int i = length;
    
    if(aux==1){
        printf("\nNovo valor do length: %d\n", length);
        printf("Vetor não organizado com o novo valor inserido no final da heap:\n" );
        printa(a, length);

        printf("Começando a Inserção no Heap:\n");
    }
    while(i > 0){
        int parent = i/2;

        if(priority == 1){     //para max heap
            if( a[i] > a[parent]){
                if(aux == 1){
                    printf("O valor do child de indice %d é maior que o valor do parent %d\n",i, parent );
                    printf("Antes do swap do %d child e %d parent:\n    ", a[i], a[parent]);
                    for (int i = 1; i <= length; ++i)
                        printf("%d ", a[length]);
                    printf("\n\n");
                }

                swap(&a[parent], &a[i]);
                
                if(aux == 1){
                    printf("    Depois do swap do %d child e %d parent:\n    ", a[i], a[parent]);
                    printa(a,length);
                }
                
                i = parent;
            }
            else 
                return;
        }
        if(priority == 2) //para min heap
        {
            if( a[i] < a[parent])
            {
                if(aux == 1){
                    printf("O valor do child de indice %d é menor que o valor do parent %d\n", i, parent );
                    printf("Antes do swap do %d child e %d parent:\n    ", a[i], a[parent]);
                    for (int i = 1; i <= length; ++i)
                        printf("%d ", a[length]);
                    printf("\n\n");
                }
                
                swap(&a[parent], &a[i]);
                
                if(aux == 1){
                    printf("Depois do swap do %d child e %d parent:\n", a[i], a[parent]);
                    printa(a,length);
                }
                printa(a,length);
                
                i = parent;
            }
            else 
                return;
        }
    }
}
int deleteNode(int *a, int length, int priority, int index, int lastIndex, int aux) {    
        int lastElement = a[length];

        a[index] = lastElement;  
        length-=1;
        
        if(aux==1){
            printf("Vetor quando o valor do último nó foi para o nó com maior prioridade:\n");
            printa(a, length);
        }

        if (length == 0) return 0;       //removeu o ultimo nó do heap.
        
        if(priority == 1) maxHeapify(a, length, 1, priority, lastIndex, aux);
        if(priority == 2) minHeapify(a, length, 1, priority, lastIndex, aux);
        
        return length;
}
void buildHeap(int *a, int heapsize, int priority, int lastIndex, int aux){
    int i;
    for (i = heapsize/2; i > 0; --i){ 
        if(priority == 1)
            maxHeapify(a, heapsize, i, priority, lastIndex, aux);
        if(priority == 2)
            minHeapify(a, heapsize, i, priority, lastIndex, aux);
    }
}
void heapSort(int *a, int heapsize, int priority, int aux){
    int i;
    int lastIndex = heapsize;

    if ( aux == 1)   
        printf("\nCriando a Max Heap:\n");
    
    buildHeap(a, heapsize, priority, lastIndex, aux);    
    
    if ( aux == 1) {
        printf("\nMax Heap feita:\n");
        printa(a, lastIndex);
    }
    for (i = heapsize; i>1; --i) // Mostrar essa parte no print.
    {
        swap(&a[i], &a[1]);
        heapsize--;
        if(priority == 1)   maxHeapify(a, heapsize, 1, priority, lastIndex, aux);
        if(priority == 2)   minHeapify(a, heapsize, 1, priority, lastIndex, aux);
    }
}
int main (){
    printf("Qual o length do Heap que vai ser criado?\n");
    int length;
    
    scanf("%d", &length);
    
    int *ptr = malloc(length*sizeof(int) );
    
    srand(time(0));
    for (int i = 1; i <= length; ++i)
        ptr[i] = rand()%100;
        
    printf("\nEscolha uma das opções abaixo:\n");
    printf("(1) Criar o heap de máximo\n");
    printf("(2) Criar o heap de mínimo\n");
    
    int priority;
    scanf("%d", &priority);
    int count=0;
    while(1){
        int res;
        int aux;
        printf("\nEscolha uma das opções abaixo:\n");
        if( count == 0 ){
            printf("(3) Você deseja visualizar apenas o resultado da criação do heap?\n");
            printf("(4) Mostrar os passos da ordenação do heap.\n");
        }
        printf("(5) Inserir um novo elemento no heap, já existente, e mostrar o heap.\n");
        printf("(6) Remover um elemento do heap. É necessário informar o índice do elemento.\n");
        printf("(7) Alterar a prioridade de um elemento do heap. É necessario informar o índice do elemento e a nova prioridade.\n");
            
        scanf("%d", &res);

        if(res == 3){
            aux = 2;

            heapSort(ptr,length, priority, aux);
            
            printf("\nVetor ordenado:\n");
            printa(ptr, length);
        }
            
        if(res == 4){
            aux = 1;

            printf("\n\nVetor não ordenado:\n");
            printa(ptr, length);
                
            heapSort(ptr,length, priority,aux);
                
            printf("\nVetor ordenado:\n");
            printa(ptr, length);
        }
        if(res == 5){
            printf("Digite o valor que você quer inserir na heap:\n");
            printa(ptr, length);
            int value;
            scanf("%d", &value);

            printf("\nVocê deseja visualizar o processo em etapas?\n");
            printf("(1)Sim\n(2)Não\n");
            scanf("%d", &aux);

            heapSort(ptr,length, priority, aux);
            
            printf("\nHeap já existente:\n");
            printa(ptr, length);
            
            insertionHeap(ptr, length, value, priority, aux);
            length +=1;

            printf("\nNovo max-heap:\n");
            printa(ptr, length);
        }
        if(res == 6){
            printf("Você pode remover um elemento do índice 1 até o índice %d.\nQual índice você quer remover?\n", length);
            int index;
            scanf("%d", &index);
            
            printf("\nVocê deseja visualizar o processo em etapas?\n");
            printf("(1)Sim\n(2)Não\n");
            scanf("%d", &aux);

            heapSort(ptr,length, priority, aux);
            
            printf("\nHeap antes de acontecer o deletar do indice:\n");
            printa(ptr, length);

            length = deleteNode(ptr, length, priority, index, length, aux);
            
            if(length==0){
                printf("O heap foi totalmente excluído\n");
                return 0;    
            }
            else{
                printf("\nHeap após ser deletado o valor:\n");    
                printa(ptr, length);
            }
        }
        if(res == 7){
            int index, key;
            printf("\nVocê pode alterar a prioridade do heap do índice 1 ao indice %d.\n", length);

            printf("\nVocê deseja visualizar o processo em etapas?\n");
            printf("(1)Sim\n(2)Não\n");
            scanf("%d", &aux);

            heapSort(ptr,length, priority, aux);
        
            printf("\nDiga qual será o índice a ser alterado a prioridade?\n");
            printa(ptr, length);
            scanf("%d", &index);
            
            printf("\nQual será a nova prioridade do índice alterado?\n");
            scanf("%d", &key);

            if(ptr[index] > key)
                decreaseKey(ptr, key, index, length, priority, aux);
            else
                increaseKey(ptr, key, index, length, priority, aux);

            printf("\nHeap depois de acontecer a troca da prioridade do elemento:\n");
            printa(ptr, length);

        }
    printf("Você pode continuar outros processos na heap feita anteriormente\n");
    
    count=1;
    }
    free(ptr);
    return 0;
}
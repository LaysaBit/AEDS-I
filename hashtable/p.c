#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { 
    int data;         
    struct node *next;
} node;

int hash(int key, int length)
{
    int r = key % length;
    return r;
}
void freeTable(node **table, int length)
{
    node *temp, *prev;
    for (int i = 0; i < length; ++i)
    {
        temp = table[i];
        prev = temp;
        while(temp != NULL ){
            prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(table);
}
int isItNull(node **table, int length)
{
    for (int i = 0; i < length; ++i)
        if(table[i] != NULL)
            return 1;
    return 0;
}
void printa(node **table, int length)
{
    node *temp;
    int isItNul = isItNull(table, length);
    int flag = 0;

    if(!isItNul){    
        printf("A Lista está vazia, nada para ser visualizado.\n");
        return;
    }

    for(int i = 0; i < length; ++i)
    {
        temp = table[i];
        while(temp != NULL){ 
            printf("No indice %d da tabela: %d\n", i, temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int searchValue(node ** table, int key, int length, int aux)         //busca se o valor ja existe na table, para nao repeti-lo.
{
    int r = hash(key, length);
    node *temp = table[r];
    int isItNul = isItNull(table, length);
    
    if(!isItNul && aux != 1){    
        printf("A Lista está vazia, nenhum valor para ser buscado.\n");
        return 0;
    }

    while(temp != NULL){
        if(temp->data == key){
            if (aux == 3) printf("Elemento encontrado no indice %d da tabela.\n", r);
            return 1;
        }
        temp = temp->next;
    }
    if (aux == 3) printf("Valor %d não se encontra na tabela.\n", key);
    return 0;
}
void removeValue(node **table, int key, int length, int aux)
{
    int isItNul = isItNull(table, length); // Detectar se a lista está vazia.
    if(!isItNul){    
        printf("A Lista está vazia, nada para ser removido.\n");
        return;
    }

    int rep = searchValue(table, key, length, aux); 
    if(!rep){  
        printf("Valor %d nao esta presente na tabela.\n", key);
        return;
    }

    int r = hash(key, length);

    node * temp = table[r];
    node * prev = temp;
    while( (temp->data != key) && (temp != NULL) ){
        prev = temp;
        temp = temp->next;
    }

    if( (temp == table[r]) && (temp->next == NULL) )
        table[r] = NULL;
    else if( (temp == table[r]) && (temp->next != NULL) )
        table[r] = temp->next;
    else
        prev->next = temp->next;
    
    free(temp);

    printf("Valor %d deletado com sucesso.\n", key);
}
void insert( node **table, int key, int length, int aux)
{
    int rep = searchValue(table, key, length, aux);
    if(rep){
        printf("Valor ja esta inserido na tabela.\n");
        return;
    }
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = key;
    
    int r = hash(key, length);
    if(table[r] == NULL)             //Insercao quando e o primeiro no a ser inserido naquela posicao
        newnode->next = NULL;
    else                                 //fazendo uma lista encadeada na posicao r.
        newnode->next = table[r];
    
    table[r] = newnode;

    printf("Valor %d inserido com sucesso na tabela.\n", key);
}
int main ()
{
    node *table[29];
    int a, choice;

    memset(table, 0, sizeof(table));
    int length = sizeof(table)/sizeof(table[0]); 

    printf("            Processo de criacao de uma tabela hash.\n");
    while(1)
    {
        printf(" 1- Voce deseja inserir algum valor na tabela?\n");
        printf(" 2- Voce quer excluir algum valor na tabela?\n");
        printf(" 3- Voce deseja buscar por um valor na tabela?\n");
        printf(" 4- Voce quer visualizar a tabela?\n");
        printf(" 5- Pretende encerrar o programa?\n");
        scanf("%d", &choice);
        
        if(choice == 1){
            printf("Insira o valor que voce deseja na tabela.\n");
            scanf("%d", &a);
            insert(table, a, length, choice);
        }
        else if(choice == 2){
            printf("Insira o valor que voce deseja remover.\n");
            scanf("%d", &a);
            removeValue(table, a, length, choice);
        }
        else if(choice == 3){
            printf("Que valor voce deseja buscar?\n");
            scanf("%d", &a);
            searchValue(table, a, length, choice);
        }
        else if(choice == 4) printa(table, length);
        else if(choice == 5) return 0;
        else    printf("\nInsira um número válido: de 1 a 5.\n");
    }
    
    freeTable(table, length);
    return 0;
}
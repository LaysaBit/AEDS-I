#include <stdio.h>
#include <stdlib.h>

// ESSE É UM CODIGO DE LISTA CIRCULAR BASEADO EM ELEMENTO.

typedef struct node { 
    int data;         
    struct node *next;
    struct node *prev;
} node;
int findLength(node *head) // acha a quantidade de nós que tem na lista.
{
    node *temp = head;
    int i = 1;
    while(1){
        temp = temp->next;
        ++i;
        if(temp == head)
            break;
    }
    return i;
}
void freeList(node *head) // função libera cada ponteiro da lista.
{
    node *temp = head;
    while(1){
        node *next = temp->next;
        free(temp);
        temp = next;
        if (temp == head)
            break;
    }
}
void displayData(node *head) // função de impressão de elementos.
{
    printf("Lista : ");
    node *temp = head;
    while(1){
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == head)
                break;
    }
    printf("\n");
}
node * searchPositionByValue(node *head, int k){  // Acha a posição para as funções de Inserção.                      
        node * temp = head;                      // Ex: Lista: 1 4 5 6, quero inserir ordenadamente o numero 3.
        while(k > temp->data){                  // onde ele vai entrar? Na posição 2 da lista : 1 2 4 5 6.
            temp = temp->next;
            if(temp == head)
                break;
        }
    return temp;
}
node * searchData(node * head, int k) // função que faz busca por elemento.
{
    node *temp = head;
    while(1){
        if(temp->data == k)
            return temp;

        temp = temp->next;
        if(temp == head)
            break;
    }
    return NULL;
}
node * deleteBeginning(node *head) // Deleta o primeiro nó da lista.
{
    node * firstnode = head;
    node * secnode = head->next;
    secnode->prev = head->prev;
    head->prev->next = secnode;

    free(firstnode);
    head = secnode;
    return head;
}
node * deleteElement(node *head, node *tail, int k){
    node * temp = searchData(head, k);
    if(temp != NULL){
        if (temp == tail)
        {
            tail->prev->next = head;
            tail = tail->prev;
            head->prev = tail;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        
        free(temp);
        printf("Elemento %d deletado com sucesso.\n", k);
        return tail;                                        //Mesmo se ele n excluir o tail e der um novo
    }                                                       // resultado pro tail, ele retorna o tail.
    else printf("Elemento %d não contido na lista.\n", k);
    return NULL;
}
node * insertElement(node *head, node *tail, int k)
{                                                     
    node *newnode = (node*)malloc(sizeof(node));             
    node *result = searchData(head, k);

    if (result == NULL){
        node *pos = searchPositionByValue(head, k);
        newnode->data = k;
        newnode->next = head;
        newnode->prev = tail; 
    
        tail->next = newnode;
        tail = newnode;
        
        printf("Elemento %d foi inserido na lista com sucesso.\n", k);
        return tail;
    }
    else printf("Elemento já está inserido na lista.\n");
    return NULL;
}
node * insertAtBeginning(node *head, int k, node *tail) // inserção depois do nó cabeça.
{   
    node * result = searchData(head, k);
    if (result == NULL)
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = k;
        
        if(tail == head){
            tail = newnode;
            tail->next = head;
            head->prev = tail;
        }

        newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
        
        printf("Elemento %d foi inserido na lista \n", k);
        return head;
    }
    else printf("Elemento %d já está inserido na lista.\n", k);
    return NULL;
}
int main (){




    return 0; 
}
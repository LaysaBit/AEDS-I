#include <stdio.h>
#include <stdlib.h>

// ESSE É UM CODIGO DE LISTA CIRCULAR BASEADO EM POSIÇÃO.

typedef struct node { 
    int data;         
    struct node *next;
    struct node *prev;
} node;
int searchPositionByRef(node *head, node *search) // acha a posição que o ponteiro está na lista para deletar.
{
    int pos = 1;
    node * temp = head;
    while(temp != search){
        temp = temp->next;
        ++pos;
    }
    return pos;
}
int searchPositionByValue(node *head, int k){ // Acha a posição para as funções de Inserção.
    int pos = 1;                               // Ex: Lista: 1 4 5 6, quero inserir ordenadamente o numero 3.
        node * temp = head;                   // onde ele vai entrar? Na posição 2 da lista : 1 2 4 5 6.
        while(k > temp->data){
            temp = temp->next;
            ++pos;
            if(temp == head)
                break;
        }
    return pos;
}
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
void deletePosition(node *head, int pos) // Deleta elementos que não estão na 1ª ou ultima posição da lista.
{                                        ////TODO: criar direto pra elemento.
    int i = 1;
    node * temp = head;
    while(i < pos){
        temp = temp->next;
        ++i;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
        
    free(temp);
    printf("Posição %d deletada com sucesso.\n", pos);
}
node * deleteEnd(node *tail, node *head) // deleta o ultimo nó e muda os dados do rabo da lista.
{     
    node *temp = tail;

    tail->prev->next = head;
    tail = tail->prev;
    head->prev = tail;

    free(temp);
    return tail;
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
node * insertEnd(node *head, node *tail, int k)
{                                                     
    node *newnode = (node*)malloc(sizeof(node));             
    node *result = searchData(head, k);

    if (result == NULL){
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
void insertAtPos(node *head, int pos, int k) //TODO: criar direto pra elemento.
{
    int i = 1;
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    
    node * temp = head;
    while(i < pos-1){
        temp = temp->next;
        ++i;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next    = newnode;
    newnode->next->prev = newnode;
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
    node *head = 0, *tail = 0, *newnode = 0, *search = 0, *result = 0;
    int choice, choice2, length, pos, k;

    printf("Crie o primeiro nó:\n");
    newnode = (node*)malloc(sizeof(node));

    head = newnode;
    tail = head;
    head->next = head;
    head->prev = head;

    printf("Dê um valor para ser inserido no primeiro nó:\n");
    scanf("%d", &newnode->data);

    while(1){
        printf("(1) Você deseja fazer outros nós?\n");
        printf("(2) Você deseja excluir algum elemento?\n");
        printf("(3) Você deseja visualizar a lista criada?\n");
        printf("(4) Você deseja buscar por algum elemento?\n");
        printf("(0) Finalizar o programa.\n");
        scanf("%d", &choice);
        
        if(!choice) break;
        else if(choice == 1)
        {
            printf("Como você deseja fazer a inserção na lista:\n"); 
            printf("(0)No início da lista ou (1)De forma crescentemente ordenada?\n");
            scanf("%d", &choice2);
            
            if(choice2 == 0){ 
                printf("Insira o valor inteiro que você deseja no novo nó:\n");
                scanf("%d", &k);
                insertAtBeginning(head, k, tail);

                printf("Lista criada:\n");
                displayData(head);
            }
            else if(choice2 == 1){ 
                printf("Inserir de forma crescente pode ser feito até numa lista não ordenada.\n");
                printf("O que será feito é que o elemento que você vai inserir vai estar numa posição maior na lista do que o elemento de menor valor.\n");
                printf("Insira o valor inteiro que você deseja no novo nó:\n");
                scanf("%d", &k);
                
                pos = searchPositionByValue(head, k);
                length = findLength(head);
        
                if(pos > length){
                    
                    result = insertEnd(head, tail, k);
                    if(result != NULL)
                        tail=result;
                }
                if(pos == 1){
                    result = insertAtBeginning(head, k, tail);
                    if(result != NULL)
                        head = result;
                }
                else
                    insertAtPos(head, pos, k);

                displayData(head);
            }
            else printf("Número inválido.\n");

        }
        else if (choice == 2){
            displayData(head);
            printf("Que elemento você deseja excluir?\n");
            scanf("%d", &k);
            
            search = searchData(head, k);
            if(search == NULL)
                printf("Elemento não está na lista.\n");
            else{
                pos = searchPositionByRef(head, search);
                
                if(pos == 1){
                    head = deleteBeginning(head);
                }
                else if (pos == length)
                    tail = deleteEnd(tail, head);
                else
                    deletePosition(head, pos);
                
                if(head != NULL)
                    displayData(head);
            }
        }
        else if (choice == 3)
            displayData(head);
        
        else if (choice == 4){
            printf("Que elemento você deseja buscar?\n");
            scanf("%d", &k);
            
            search = searchData(head, k);
            if (search == NULL)
                printf("Elemento não está contido na lista.\n");
            else 
                printf("Elemento está contido na lista.\n");
        }
        else printf("Número inválido.\n");
    }
    
    freeList(head);
    head = NULL;
    tail = NULL;
    newnode = NULL;
    search = NULL;
    result = NULL;
    return 0;
}
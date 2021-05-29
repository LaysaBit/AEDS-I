#include <stdio.h>
#include <stdlib.h>

typedef struct node { //Como criar um byte. Essa struct node tem X bytes.
    int data;         //Doubly linked list usa mais memória que singly linked list.
    node *next;
    node *prev;
} node;

int findLength(node *head)
{
    node *temp = head;
    int i = 0;
    while(temp != 0){
        temp = temp->next;
        ++i;
    }
    return i;
}
void freeList(node *head)
{
    node *temp = head;
    while(temp != 0){
        node *next = temp->next;
        free(temp);
        temp = next;
    }
}
node * searchData(node * head, int k)
{
    node *temp = head;

    while(temp->next != 0){
        temp = temp->next;
        
        if(temp->data == k)
            return temp;
    }
    return NULL;
}
void displayData(node *head)
{
    printf("Lista : ");
    node *temp = head;
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteElement(node *head, int k)
{
    node * result = searchData(head, k);
    node * temp = head;

    if(result != NULL)
    {
        while(i < result){
            temp = temp->next;
            ++i;
        }
        temp->prev->next = temp->next;
        temp->next->prev= temp->prev;
        
        free(temp);
        printf("Elemento %d deletado com sucesso.\n", k);
    }
    else printf("Elemento %d inexistente na lista.\n", k);
}
void deletePosition(node *head, int pos)
{
    node * temp = head;
    while(i < pos){
        temp = temp->next;
        ++i;
    }
    temp->prev->next = temp->next;
    temp->next->prev= temp->prev;
        
    free(temp);
    printf("Posição %d deletada com sucesso.\n", pos);
}
void deleteEnd(node *tail, node *head)
{     
    if (tail == 0)
        printf("A lista está vazia.\n");
    else{
        node *temp = tail;
        
        if(tail == head)
            printf("A lista foi totalmente excluída.\n");
        else{
            tail->prev->next = head;
            tail = tail->prev;
        }
        free(temp);
    }
}
void deleteBeginning(node *head)
{
    node *temp = head;
    head = temp->next;
    head->prev = 0;
    free(temp);

    if(head == 0)
        printf("A Lista foi totalmente deletada");
}
void insertAtPos(node *head, node *newnode, int pos)
{
    int i = 1;
    newnode = (node*)malloc(sizeof(node));
    
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    
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
void insertBeginning(node *head, node *newnode, int k)
{   
    node * result = searchData(head, k);
    if (result == NULL){
        newnode = (node*)malloc(sizeof(node));
        newnode->data = k;
        
        newnode->next = head;
        newnode->prev = 0;
        
        head = newnode;
    }
    else printf("Elemento %d já inserido na lista.\n", k);
}
void insertEnd(node *head, node *newnode, node *tail, int k)
{                                                     
    newnode = (node*)malloc(sizeof(node));             
    int choice;
    node *result;

    result = searchData(head, k);
    if (result == NULL){
        newnode->data = k;
        newnode->next = 0; 
        if(head == 0) {// Primeiro node criado
            head = newnode = tail;           
            newnode->prev = 0;
        }
        else{
            head->next = newnode; //isso aqui ta errado?
            newnode->prev = tail;
            tail = newnode;
        }
    }
}
int main (){
    node *head = 0, *newnode = 0, *tail = 0;
    int choice, length, pos, k;

    printf("Crie o nó cabeça:\n")
    insertEnd(head, newnode, tail);
    While(1){
        printf("Você deseja fazer outros nós? (0)Não  (1)Sim\n");
        scanf("%d", &choice);
        
        if(!choice) break;
        else if(choice == 1) insertEnd(head, newnode, temp);
        else printf("Número inválido. Presse 0 para NÃO ou presse 1 para SIM\n");
    }
    printf("Você deseja visualizar a lista encadeada?\n");
    scanf("%d", &choice);

    if(choice == 1) displayData(head); //TERMINAR;
    else if(choice != 0) printf("Número inválido. Presse 0 para NÃO ou presse 1 para SIM\n");

    length = findLength(head);
    if(pos==1)
        insertBeginning(head, newnode);
    else if(pos<length)
        insertAtPos(head, newnode, temp, pos);
    else if(pos == length)
        insertEnd(head, newnode, tail);
    else
        printf("Posição inválida, insira uma posição menor ou igual ao tamanho %d da lista\n", length);

    freeList(head);
    free(head);
    free(newnode);
    free(tail);
    return 0;
}
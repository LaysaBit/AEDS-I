#include <stdio.h>
#include <stdlib.h>

//This one is a stack code based on linked list.
typedef struct node{
    int c;
    struct node *next;  
} node;

int busca(node *top, int k)
{
    node *temp = top->next;
    if(temp != NULL){
        while(temp != NULL){
            if (temp->c == k)
                return 1;
            temp = temp->next;
        }
        return 0;
    }
    else  return 1;
}
void push(node *top)
{
    int num;
    printf("Que elemento você deseja empilhar?\n");
    scanf("%d", &num);
    
    node * newnode = (node *)malloc(sizeof(node));
    newnode->c = num;
    if(top->next == NULL){
        top->next = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = top->next;
        top->next = newnode;
    }
}
void empty(node *top){
    node *temp = top->next;
    node *prev = temp;
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        pop(prev);
    }
}
void pop(node *top){
    if(top->next != NULL){
        node * p = top->next;
        top->next = top->next->next;

        printf("Desempilhado com sucesso! Valor: %d", p->c);
        free(p);
    }
    else printf("Nada desempilhado, pois lista está vazia.\n");
}
int main ()
{
    node * top = (node *)malloc(sizeof(node));
    
    push(top);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node *next;
} node;
void display( node * front){
    node * temp = front;
    while(temp != NULL){
        printf("%d ", temp->n);
        temp = temp->next; 
    }
    printf("\n");
}
node * createNode(){
    node * newnode = (node*)malloc(sizeof(node));

    printf("Insira o valor de um inteiro.\n");
    scanf("%d", newnode->n);
    newnode->next = NULL;

    return newnode;
}
node * enqueue(node * front, node * rear){
    node *newnode = createNode();

    if(front == rear){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}
node * dequeue(node *front){
    if(front == NULL){
        printf("Não há nada para ser deletado pois a lista está vazia.\n");
        return;
    }
    node * temp = front;
    front = front->next;
    
    free(temp);
}
int main (){
    node *front = NULL, node *rear = NULL;

    return 0;
}
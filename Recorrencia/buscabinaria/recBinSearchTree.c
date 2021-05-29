#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int c;
    struct node *l;
    struct node *r;
}node;

node * createNode(int k){
    node newnode = (node*)malloc(sizeof(node));
    newnode.c = k;
    newnode.l = NULL;
    newnode.r = NULL;

    return newnode;
}
void insert (node **head, int k){
    
    if(*head == NULL){
        *head = createNode(k);
        return;
    }
    else
    {
        if( newnode->c > (*head)->l)
            insert( &((*head)->l), k);
    
        if( newnode->c > (*head)->r)
            insert( &((*head)->r), k);
    }
}
int main (){
    node * head = NULL;

    
    return 0;
}
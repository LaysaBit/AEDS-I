#include <stdio.h>
#include <stdlib.h>

typedef struct node { //Como criar um node. Essa struct node tem X bytes.
    int data;
    node *next;
} node;

typedef struct list_t{
    node * first;
    node * end;
} list;

list * newList(){
    list * lst = (list*)calloc( 1, sizeof(list));
    lst->first = NULL;
    lst->end = NULL;
    return lst;
}

void insertIntoList(list* lis, int i){
    node* nodepointer = (node*)calloc(1, sizeof(node));
    nodepointer->data = i;
    nodepointer->next = NULL;
    
    if(lst->first == NULL && lst->end == NULL){
        lst->first = nodepointer;
        lst->end = nodepointer;
    }
    else{
        lst->end->next = nodepointer;
        lst->end = nodepointer;
    }
}

void printaData(node *head){
    node *temp = head;
    while(temp != 0){
        printf("%d", temp->data);
        temp = temp->next;
    }
}
void deleteBeginning(node *head){
    node *temp = head;
    head = head->next;
    free(temp);
}
void deletePos(node *head, node *newnode, node *temp){
    node *nextnode;
    int pos, i = 1;
    printf("Qual posição deseja deletar?\n");
    scanf("%d", &pos);
    
    temp = head;
    while(i < pos-1){
        temp = temp->next;
        ++i;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
void deleteEnd(node *head, node *newnode, node *temp){
    node * prevnode;
    
    temp = head;
    while(temp->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    
    if(temp == head)   head = 0;
    else   prevnode->next = 0 ;
    
    free(temp);
}
void insertLocation(node *head, node *newnode, node *temp){
    int i=1, pos;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    
    printf("Qual posição deseja botar o nó?\n");
    scanf("%d", &pos); //ver se a posição é válida.
    
    temp = head;
    while(i < pos){
        temp = temp->next;
        ++i;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void insertInicio(node *head, node *newnode, node *temp){
    newnode = (node*)malloc(sizeof(node));

    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next=head;       
    head = newnode;
}
void criarNode(node *head, node *newnode, node *temp){//essa função cria um node de cada vez e insere no final.
    newnode = (node*)malloc(sizeof(node)); 
    int choice;

    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next=0;            //criou um node.
        
    if(head == 0) // Primeiro node criado
        head = newnode = temp;
    else{
        temp->next = newnode;
        temp = newnode;
    }
}
int main (){
    node *head = 0, *newnode = 0, *temp = 0;
    int choice = 1;
    
    //Criando um node de cada vez.
    criarNode(head, newnode, temp);
    printf("Você quer criar outro node para a singly linked list? (0) Não, (1)Sim\n");
    scanf("%d", &choice);
    if(choice==1) criarNode(head, newnode, temp);

    //Para visualizar o campo data.
    //printaData(temp);

    //Processo de Inserção.
    //insertInicio(head, newnode, temp);
    //insertLocation(head, newnode, temp);
    
    //Deletar Nó.
    deleteBeginning()

    return 0;
}

#include "menu.h"

group * nodeGroups(cadastro *user){
    group *newnode = (group*)malloc(sizeof(group));
    integrantes * user1 = criarIntegrantes(user);
    newnode->adm   = user;
    newnode->head4 = user1;
    newnode->head5 = NULL;
    newnode->next  = NULL;

    printf("Qual será o nome do grupo de no máximo 50 caracteres?\n");
    getString(newnode->name, 50);

    printf("Dê uma descrição ao grupo de no máximo 300 caracteres:\n");
    getString(newnode->about, 300);

    return newnode;
}
void showIntegrantes(integrantes *head){
    integrantes *temp = head;

    printf("Os integrantes são:\n");
    while(temp != NULL){
        printf("Nome: %s\n", temp->user->name);
        temp = temp->next; 
    }
    printf("\n");
}

integrantes * criarIntegrantes(cadastro *user){
    integrantes * newnode = (integrantes*)malloc(sizeof(integrantes));
    newnode->user = user;
    newnode->next = NULL;

    return newnode;
}
void initialInsertUser(integrantes ** head, cadastro *user){ //Faz inserção no inicio
    integrantes * newnode = criarIntegrantes(user);
    newnode->next = (*head);
    (*head) = newnode;
}
void insertUser(integrantes **prev, integrantes ** temp, cadastro *user){ //Faz a inserção no meio/final
    integrantes * newnode = criarIntegrantes(user);
    newnode->next = (*temp);
    (*prev)->next = newnode;
}
void addUserToGroup(group ** grupo, cadastro *user){
    integrantes * temp = (*grupo)->head4;
    integrantes *prev = temp; 
    while(temp != NULL){
        int result = strcmp( (*user).name, temp->user->name ); 
        if( result < 0){
            if(temp == (*grupo)->head4){
                initialInsertUser(&temp, user); //insere usuario no inicio da lista de integrantes.
                return;
            }
            else{
                insertUser(&prev, &temp, user); //insere o usuario no meio/final da lista de integrantes.
                return;
            }
        }
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            insertUser(&prev, &temp, user); //insere o usuario no meio/final da lista de integrantes.
            return;
        }
    }
}
group * findGroupByName(group *head6, char *name){
    group * temp = head6;
    
    if(temp == NULL){
        printf("Não há nenhum grupo para você entrar.\n");
        return NULL;
    }
    while(temp != NULL){
        if(strcmp(name, temp->name) == 0)
            return temp;
        temp = temp->next;
    }
    printf("Não há nenhum grupo com esse nome.\n");
    return NULL;
}
void showGroups(group *head6){
    group *temp = head6;

    if(temp == NULL){
        printf("Você não possui grupos.\n");
        return;
    }
    printf("\n");
    while(temp != NULL){
        printf("O nome do grupo:%s\n", temp->name);
        printf("Descrição do grupo:\n%s\n\n", temp->about);

        temp = temp->next;
    }
}
void noGroups(group **head6, group **grupo, cadastro *user){ //primeiro grupo criado
    *head6 = (*grupo);
    (*user).head4 = *head6;
    printf("Grupo feito com sucesso!\n");
}
void initialGroups(group **head6, group ** newnode){ //fazendo inserção no inicio
    (*newnode)->next = *head6;
    *head6 = *newnode;
}
void orderGroups(group **prev, group **temp, group** newnode){ //fazendo inserção meio/final
    (*newnode)->next = (*temp);
    (*prev)->next = *newnode;
}
void newGroup(group **head, group **newnode){ //criando novo grupo (quando já existe um primeiro)
    group * temp = *head;
    group * prev = temp;
    
    while(temp != NULL){
        int result = strcmp((*newnode)->name, temp->name);
        if( result < 0){
            if( temp == *head){
                initialGroups(head, newnode);
                return;
            }
            else{
                orderGroups(&prev, &temp, newnode);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            orderGroups(&prev, &temp, newnode);
            return;
        }    
    }
}
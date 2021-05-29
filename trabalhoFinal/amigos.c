#include <ctype.h>
#include "menu.h"

void showUsers(cadastro *users, int quantity){
    for (int i = 0; i < quantity; ++i) //Ta pronto.
        printf("%s\n", users[i].name);
}
int findUserByName(cadastro *users, int quantity, char* name){ //Você pode melhorar essa função.
    for (int i = 0; i < quantity; ++i){ 
        if(strcmp(users[i].name, name) == 0)
            return i;
    }
}
char* toLower(char* s) { 
    for(char *p = s; *p; p++)
        *p = tolower(*p);
    return s;
}
int quantityFriends(friends * head){ 
    int i = 0;
    friends *temp = head;

    while(temp != NULL){
        ++i;
        temp = temp->next;
    }
    return i;
}
int areTheyFriends(char* name, friends* head, cadastro *users, char *email, int quantity){ 
    int i, result;
    friends *temp = head;
    i = findUser(users, quantity, email);
    
    if(strcasecmp(users[i].name, name) == 0 ){
        printf("Você não pode adicionar a si mesmo.\n");
        return 2;
    }

    while(temp != NULL){
        result = strcmp(head->user->name, name);
        if(result == 0){
            printf("Você já o possui como amigo\n");
            printf("Adicione outra pessoa\n");
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
friends* createFriends(cadastro *user){ //apenas cria o novo nó.
    friends *newnode = (friends*)malloc(sizeof(friends));
    newnode->user = user;
    newnode->next = NULL;

    return newnode;
}
void noFriends(cadastro *users, friends** head){
    friends *newnode = (friends*)malloc(sizeof(friends));
    newnode->user = users;
    newnode->next = NULL;
    
    (*head) = newnode;
}
void middleOrEnd(friends **prev, friends** temp, cadastro *users){
    friends *newnode = createFriends(users);
    newnode->next = (*temp);
    (*prev)->next = newnode;
}
void initialInsert(friends **head, cadastro *user){
    friends *newnode = createFriends(user);
    newnode->next = (*head);
    (*head) = newnode;
}
void insertAndOrder(cadastro *user, friends** head, char* name){
    int result;
    friends* temp = (*head);
    friends* prev = temp;
    while(temp != NULL)
    {
        result = strcmp(name, temp->user->name);
        if(result < 0){ //name deve ser menor do que o nome que está na lista de amigos.
            if(temp == (*head)){
                initialInsert(head, user);
            }
            else{
                middleOrEnd(&prev, &temp, user);
            }
            return;
        }
        prev = temp;
        temp = temp->next;
        if(temp == NULL)
            middleOrEnd(&prev, &temp, user);
    }
}
void addFriends(cadastro *users, int quantity, friends** head, char*email){
    int i, j, k, aux, choice;
    char name[151];

    printf("Essas são as pessoas que você pode adicionar:\n");
    showUsers(users, quantity);
    
    printf("\nQuem você deseja adicionar?\n"); 
    getString(name, 150);
    
    aux = areTheyFriends(name, *head, users, email, quantity);
    if(aux == 1){
        printf("Você já é amigo dessa pessoa.\n");
        return;
    }
    if(aux == 2) return;
    
    i = findUserByName(users, quantity, name);
    k = quantityFriends(*head);
    
    if(k == 0)
        noFriends(&users[i], head);
    else
        insertAndOrder(&users[i], head, name);
    printf("Sua lista de amigos foi atualizada!\n");

    j = findUser(users, quantity, email); //j é pro sistema da pessoa
    k = quantityFriends(users[i].head2); //i quem queremos adicionar
    if(k == 0)
        noFriends(&users[j], &users[i].head2);
    else
        insertAndOrder(&users[j], &users[i].head2, users[j].name);
    
    printf("A lista de amigos do(a) %s foi atualizada!\n", users[i].name);

    printf("1- Você deseja ver o mural de algum amigo?\n");
    printf("2- Voltar ao menu.\n");
    choice = getInt();

    if(choice == 1)
    {
        k = quantityFriends(*head);

        if(k == 1){
            printf("A mural do amigo(a) %s é :\n", users[i].name);
            printaBoard(&((*head)->user->head));
            return;    
        }
        printf("Que amigo você deseja ver o mural?\n");
        getString(name,150);
        
        i = findUserByName(users, quantity, name);
        printaBoard(&users[i].head);
    }
    
}
void showFriends(cadastro *users, int quantity, friends** head, char *email){
    int choice, i, k;
    char name[151];
    if(*head != NULL)
    {
        printf("Sua lista de amigos é:\n");
        friends *temp = (*head);
        
        while(temp != NULL){
            printf("%s\n", temp->user->name);
            temp = temp->next;
        }
        printf("\n");

        printf("1- Você deseja ver o mural de algum amigo?\n");
        printf("2- Voltar ao menu.\n");
        choice = getInt();

        if(choice == 1)
        {
            k = quantityFriends(*head);

            if(k == 1){
                
                printaBoard(&((*head)->user->head));
                return;    
            }
            printf("Que amigo você deseja ver o mural?\n");
            getString(name,150);
            
            i = findUserByName(users, quantity, name);
            printaBoard(&(users[i].head));
        }
    }
    else{
        printf("1- Adicione pessoas novas para podermos mostrá-los para você :)\n");
        printf("2- Voltar\n");
        choice = getInt();

        if(choice == 1)
            addFriends(users, quantity, head, email);
    }
}

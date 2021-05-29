#include "menu.h"
#include "mensagem.h"

void freeList(msg **head){
    msg *temp = *head;
    while(temp != NULL){
        msg *prev = temp->prev;
        free(temp);
        temp = prev;
    }
    free(*head);
}
void showDM(msg **head, char* email, cadastro *users, int quantity){
    int choice;
    msg * temp = *head;

    if(temp == NULL){
        printf("Você não possui mensagens novas.\n");
        return;
    }

    while(temp != NULL){
        printf("Amigo que enviou a mensagem:\n%s\n", temp->user->name );
        printf("A mensagem:\n%s\n\n\n", temp->texto);

        temp = temp->prev;
        if( temp != NULL)
            printf("Mensagem mais antiga:\n");
    }   
    printf("\n\n");

    printf("1- Você deseja responder alguém?\n");
    printf("2-Deseja voltar ao menu?\n");
    choice = getInt();
    if(choice == 1)
        sendingMsg(users, quantity, email);
    
    freeList(head);
}

void sendingMsg(cadastro *users, int quantity, char* email){
    char message[150];
    char user[151];
    int i, j;

    printf("O que você quer escrever em 150 caracteres?\n");
    getString(message, 150);
    
    j = findUser(users, quantity, email);
    printf("Para quem você deseja enviar essa mensagem?\n");
    showFriends(users, quantity, &users[j].head2, email);

    printf("\nDigite o nome da pessoa:\n");
    getString(user, 150);

    i = findUserByName(users, quantity, user);

    msg *new  = (msg*)malloc(sizeof(msg));
    strcpy(new->texto, message);
    new->user = &users[j];
    
    if(users[i].head3 == NULL){
        new->prev = NULL;
        users[i].head3 = new;
    }
    else{
        new->prev = users[i].head3;
        users[i].head3 = new;
    }
    printf("Esse é a nova mensagem mandada pro usuario: %s\n", users[i].head3->texto);
}
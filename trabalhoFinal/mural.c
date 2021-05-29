#include "menu.h"

void printaBoard(board **mural){    
    board * temp = *mural;
    
    if(temp == NULL){
        printf("Mural vazio.\n");
        return;
    }

    printf("\nPrimeira publicação:\n");
    while(temp != NULL){
        printf("%s\n", temp->publi);
        temp = temp->prevpost;
        if(temp != NULL)    printf("\nProxima Publicação:\n");
    }
    printf("Fim das publicações.\n");
    printf("\n");
}

board * createBoard(board **mural){
    board * newnode = (board*)malloc(sizeof(board));

    if(*mural == NULL){
        *mural = newnode;
    }
    else{
        newnode->prevpost = *mural;
        *mural = newnode; 
    }
    return *mural;
}
void createStory(board** mural){
 
    *mural = createBoard(mural);

    printf("O que você deseja inserir no seu novo post de 300 caracteres?\n");
    getString( (*mural)->publi, 300);

    printf("Publicação feita com sucesso! :)\n");
    
    printaBoard(mural);
}
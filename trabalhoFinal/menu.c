#include "menu.h"

void menu(cadastro *users, char* email, int *quantity, int *lengthUsers, group **head6){
    int choice, choice1, choice2, aux, j;
    char name[151];
    while(1)
    {
        printf("\n");
        printf("Bem vindo ao Menu, O que você deseja acessar?\n");
        printf("1 - Perfil\n");
        printf("2 - Seu mural\n");
        printf("3 - Lista de Amigos\n");
        printf("4 - Mensagens\n");
        printf("5 - Grupos\n");
        printf("6 - Configurações\n\n");

        int i = findUser(users, *quantity, email);       
        choice = getInt();
        if(choice == 1)     //PERFIL.
        {
            showProfile(users, *quantity, email);
            printf("1- Modifique seu perfil:\n");
            printf("2- Voltar ao menu.\n");
            choice1 = getInt();

            if(choice1 == 1)    modifyProfile(users, *quantity, email);
            else  printf("Insira um número válido: de 1 a 3.\n");
        }
        else if(choice == 2) // MURAL.
        {
            if(users[i].head == NULL){ //Se o mural estiver vazio.
                printf("Não há nada no seu mural! Compartilhe suas histórias :)\n");
                printf("1- Você deseja escrever algo novo?\n");
                printf("2- Quer voltar ao menu principal?\n");
                
                choice1 = getInt();
                if(choice1 == 1)    createStory(&users[i].head);
            }
            else if(users[i].head != NULL){ //Se o mural tiver alguma publicação.
                printaBoard(&users[i].head);

                printf("1- Você deseja escrever algo novo?\n");
                printf("2- Quer voltar ao menu principal?\n");
                choice1 = getInt();
                if(choice1 == 1)    createStory(&users[i].head);
            }
        }
        else if(choice == 3) //AMIGOS.
        {
            showFriends(users, *quantity, &users[i].head2, users[i].email);
            printf("1- Você deseja adicionar mais amigos?\n");
            printf("2- Você quer voltar ao menu inicial?\n");
            choice1 = getInt();
            if(choice1 == 1)
                addFriends(users, *quantity, &users[i].head2, users[i].email);
        }
        else if(choice == 4) //CAIXA DE MENSAGEM.
        {
            if(users[i].head3 == NULL){
                printf("\nSua caixa de mensagens está vazia.\n");
                printf("1- Escrever uma mensagem nova\n");
                printf("2- Volte ao menu principal\n\n");

                choice1 = getInt();
                if(choice1 == 1)
                    sendingMsg(users, *quantity, users[i].email);
            }
            else
                showDM(&users[i].head3, users[i].email, users, *quantity);
        }
        else if(choice == 5) //PARTE DE GRUPOS.
        { 
            group * grupo;
            printf("Bem vindo a aba de grupos.\n");
            printf("1- Quero visualizar todos os grupos cadastrados.\n");
            printf("2- Quero ver apenas meus grupos.\n");
            printf("3 - Você deseja entrar em um grupo novo?\n");
            printf("4 - Deseja ver os participantes de algum grupo?\n");
            printf("5 - Quer ver as publicações de algum grupo?\n");
            printf("6 - Deseja publicar em algum grupo?\n");
            printf("7 - Quer criar um novo grupo?\n");
            
            choice1 = getInt();
            if(choice1 == 1) //VISUALIZAR TODOS GRUPOS CADASTRADOS.
            {
                if(*head6 == NULL) //Quando não existe nenhum grupo.       
                {
                    printf("Não há nenhum grupo existente.\n");
                    continue;
                }
                if(*head6 != NULL) //Quando existe algum grupo.
                {
                    printf("Os grupos são:\n");
                    showGroups(*head6);
                }
            }
            if(choice1 == 2) //VISUALIZAR APENAS MEUS GRUPOS.
            {
                if(*head6 == NULL){
                    printf("Não há grupos para se visualizar.\n");
                    continue;
                }
                showGroups(users[i].head4);
            }
            else if(choice1 == 3)  //ENTRAR EM UM GRUPO NOVO.
            {
                if(*head6 == NULL){
                    printf("Não há grupos para entrar.\n");
                    continue;
                }
                printf("Os grupos são:\n");
                showGroups(*head6);
                printf("Que grupo você quer entrar?\n");
                getString(name, 50);
                grupo = findGroupByName(*head6, name);
                if(grupo == NULL)   continue;
                addUserToGroup(&grupo, &users[i]);

            }
            else if(choice1 == 4) //VER PARTICIPANTES DE UM GRUPO. 
            { 
                if(*head6 == NULL){
                    printf("Não há grupos para ver partcipantes.\n");
                    continue;
                }
                printf("Que grupo você quer ver os participantes?\n");
                getString(name, 50);
                grupo = findGroupByName(*head6, name);
                showIntegrantes(grupo->head4);
            }
            else if(choice1 == 5) //VER AS PUBLICAÇÕES DE UM GRUPO.
            { 
                if(*head6 == NULL){
                    printf("Não há grupos para ver publicações\n");
                    continue;
                }
                printf("Que grupo você quer ver as publicações?\n");
                getString(name, 50);
                grupo = findGroupByName(*head6, name);
                printaBoard( &(grupo->head5) );
            }
            else if(choice1 == 6)  //PUBLICAR EM UM GRUPO.
            {   
                if(*head6 == NULL){
                    printf("Não há grupos para se publicar.\n");
                    continue;
                }
                printf("Em que grupo quer publicar?\n");
                getString(name, 50);
                grupo = findGroupByName(*head6, name);
                createStory( &(grupo->head5) );
            }
            else if(choice1 == 7) //CRIAR GRUPO NOVO.
            { 
                grupo = nodeGroups(&users[i]);
                if(*head6 == NULL)       //Quando não existe nenhum grupo.
                    noGroups(head6, &grupo, &users[i]);
                else{
                    newGroup(head6, &grupo);
                    newGroup(&(users[i].head4), &grupo);
                    printf("Grupo feito com sucesso!\n");
                }
                
            }
        }
        else if(choice == 6) //CONFIGURAÇÕES
        {
            menuConfig();
            choice1 = getInt();
            setting(choice1, &users[i], users, lengthUsers, quantity, head6);
        }
        else printf("Insira um valor válido: do 1 ao 6.\n");
    }
}

void loginArea(cadastro *users, int * lengthUsers, int* quantity, group **head6){
    int escolha, result, result2;
    char email[257], senha[11];

    while(1){
        printf("Bem vindo a You-C.\n");
        printf("Você já possui cadastro? (1) Sim, (2) Não.\n");
        escolha = getInt();
        
        if(escolha == 1)
        {
            printf("Insira seu email:\n");
            getString(email, 256);

            printf("Insira sua senha:\n");
            getString(senha, 10);

            result = verifyAccount(users, *quantity, email);
            
            if(result)
            {
                result2 = verifyPassword(users, *quantity, senha, email);
                if(result2 == 1){
                    menu(users, email, quantity, lengthUsers, head6);
                }
                else if(!result2){
                    printf("Você inseriu uma senha incorreta.\n");
                    continue;
                }
            }
            if(!result) {
                printf("Esse email não está presente no sistema.\n");
                continue;
            }
        }
        if(escolha == 2){
            createAccount(users, lengthUsers, quantity);
            menu(users, users[*quantity-1].email, quantity, lengthUsers, head6);            
        }
        else printf("Insira um número válido: 1 ou 2.\n");
    }
}
#include "menu.h"
void menuConfig(){
    printf("O que deseja fazer?\n");
    printf("1- Verificar todas as informaçoes do seu perfil.\n");
    printf("2- Trocar a senha.\n");
    printf("3- Sair da sua conta.\n");
}

void setting(int choice, cadastro *user, cadastro *users, int * lengthUsers, int *quantity, group **head6){
    char passw[11], passw1[11];
    
    if(choice == 1)
    {
        printf("Seu nome: %s\n", user->name);
        printf("Seu email: %s\n", user->email );
        printf("Sua ocupação: %s\n", user->occupation);
        printf("Seu endereço: %s\n", user->adress);
        printf("Sua bio: %s\n", user->bio);
        printf("Sua senha: %s\n", user->password);
    }
    else if(choice == 2)
    {
        printf("Antes de trocar de senha, insira sua senha antiga:\n");
        getString(passw, 10);
        if( strcmp(passw, user->password) == 0 )
        {
            printf("Insira sua senha nova:\n");
            getString(passw, 10);

            printf("Confirme sua senha nova:\n");
            getString(passw1, 10);

            if(strcmp(passw, passw1) == 0){
                strcpy(user->password, passw);
                printf("Senha atualizada com sucesso!\n");
            }
            else{
                printf("As senhas estão diferentes.\n");
                setting(choice, user, users, lengthUsers, quantity, head6);
            }
        }
        else
            printf("A senha que você inseriu está errada.\n");
    }
    else if(choice == 3)
        loginArea(users, lengthUsers, quantity, head6);
}
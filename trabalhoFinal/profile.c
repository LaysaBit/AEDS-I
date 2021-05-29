#include "menu.h"
#include "basicfunc.h"
void initUsers(cadastro *users){ // Inicializando alguns cadastros
    strcpy(users[0].name, "laysa");
    strcpy(users[0].email, "laysabit");
    strcpy(users[0].password, "1");
    strcpy(users[0].occupation, "Estudante");
    strcpy(users[0].adress, "rua 0");
    strcpy(users[0].bio, "nada");
    users[0].head = NULL;
    users[0].head2 = NULL;
    users[0].head3 = NULL;
    users[0].head4 = NULL;

    strcpy(users[1].name, "tania");
    strcpy(users[1].email, "tanialucia");
    strcpy(users[1].password, "2");
    strcpy(users[1].occupation, "Trabalhador");
    strcpy(users[1].adress, "rua 1");
    strcpy(users[1].bio, "alguma coisa");
    users[1].head = NULL;
    users[1].head2 = NULL;
    users[1].head3 = NULL;
    users[1].head4 = NULL;
    
    strcpy(users[2].name, "lucia");
    strcpy(users[2].email, "luciabit");
    strcpy(users[2].password, "3");
    strcpy(users[2].occupation, "Trabalhador");
    strcpy(users[2].adress, "rua 0");
    strcpy(users[2].bio, "escrito");
    users[2].head = NULL;
    users[2].head2 = NULL;
    users[2].head3 = NULL;
    users[2].head4 = NULL;

    strcpy(users[3].name, "antonio");
    strcpy(users[3].email, "antonio");
    strcpy(users[3].password, "4");
    strcpy(users[3].occupation, "Trabalhador");
    strcpy(users[3].adress, "rua 1");
    strcpy(users[3].bio, "escrito");
    users[3].head = NULL;
    users[3].head2 = NULL;
    users[3].head3 = NULL;
    users[3].head4 = NULL;
}
int findUser(cadastro *users, int quantity, char* email){
    for (int i = 0; i < quantity; ++i)
        if(strcasecmp(users[i].email, email) == 0)
            return i;
}
void createAccount(cadastro * users, int * lengthUsers, int* quantity){
    int choice;

    if (*quantity == *lengthUsers)
        users = (cadastro *)realloc(users,(*lengthUsers+5)*sizeof(cadastro));
    (*lengthUsers) += 5;
    
    printf("Digite seu nome todo:\nMáximo de 150 caracteres.\n");
    getString(users[*quantity].name, 150);

    printf("Digite seu email todo:\nMáximo de 256 caracteres.\n");
    getString(users[*quantity].email, 256);
    
    printf("Digite sua senha:\nMáximo de 10 caracteres.\n");
    getString(users[*quantity].password, 10);
    
    while(1){
        printf("Escolha uma ocupacao:\n(1) Estudante\n(2) Trabalhador\n(3) Outro\n");
        choice = getInt();
        
        if(choice == 1){
            strcpy(users[*quantity].occupation, "Estudante");
            break;
        }    
        else if(choice == 2){
            strcpy(users[*quantity].occupation, "Trabalhador");
            break;    
        }
        else if(choice == 3){
            strcpy(users[*quantity].occupation, "Outro");
            break;    
        }
        else printf("Digite um número válido: 1, 2 ou 3.\n");
    }
    
    printf("Digite seu endereço:\nMáximo de 150 caracteres.\n");
    getString(users[*quantity].adress, 150);

    printf("Escreva algo para sua biografia:\nMáximo de 300 caracteres\n");
    getString(users[*quantity].bio, 300);

    users[*quantity].head = NULL;
    users[*quantity].head2 = NULL;
    users[*quantity].head3 = NULL;
    users[*quantity].head4 = NULL;

    *quantity += 1;
}
int verifyAccount(cadastro * users, int quantity, char* email){
    for (int i = 0; i < quantity; ++i)
        if( strcasecmp(email, users[i].email) == 0 )
            return 1;
    return 0;
}
int verifyPassword(cadastro * users, int quantity, char* password, char*email){
    int i = findUser(users, quantity, email);  
    if( strcasecmp(password, users[i].password) == 0 )
        return 1;
    return 0;
}
void showProfile(cadastro *users, int quantity, char*email){
    int i = findUser(users, quantity, email);
    
    printf("Seu nome:\n%s\n\n", users[i].name);
    printf("Sua ocupação:\n%s\n\n", users[i].occupation);
    printf("Sua bio:\n%s\n\n", users[i].bio);
    
    return;
}

void modifyProfile(cadastro *users, int quantity, char* email){
    int i = findUser(users, quantity, email);
    
    printf("Você pode modificar seu:\n(1)Nome\n(2)Ocupação\n(3)Bio\n");
    int choice = getInt();

    if(choice == 1){
        printf("Seu nome atual é:\n");
        printf("%s\n\n", users[i].name);
        
        printf("Para que nome você deseja modificar?\nApenas 150 caracteres são permitidos.\n");
        getString(users[i].name, 150);
        printf("Nome modificado com sucesso: %s\n\n", users[i].name);
    }
    else if(choice == 2){
        printf("Sua ocupacao atual é:\n");
        printf("%s\n\n", users[i].occupation);
        
        printf("Para que ocupacao você deseja modificar?\n(1)Estudante,\n(2)Trabalhador,\n(3)Outro\n");
        choice = getInt();
        if(choice == 1) strcpy(users[i].occupation, "Estudante");
        if(choice == 2) strcpy(users[i].occupation, "Trabalhador");
        if(choice == 3) strcpy(users[i].occupation, "Outro");

        printf("Ocupação atualizada com sucesso: %s\n\n", users[i].occupation);
    }
    else{
        printf("Sua bio:\n");
        printf("%s\n\n", users[i].bio);
        
        printf("Insira aqui sua nova bio de 300 caracteres:\n");
        getString(users[i].bio, 300);
        
        printf("Bio atualizada com sucesso!\n");
        printf("%s\n\n", users[i].bio);
    }
}
#include "menu.h"

int main (){
    cadastro users[300];
    group *head6 = NULL;
    int lengthUsers = 300, quantity = 4; 

    initUsers(users);
    
    loginArea(users, &lengthUsers, &quantity, &head6);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num[25], num_frequente;
int i=0, qomaisfrequente=0, aux=0;

int frequencia(char * num){
    
    ++i;
    return frequencia(num[i]);
}
int main (){
    scanf("%s", &num);
    
    
    printf("%d %d\n", num_frequente, frequencia(num));
    return 0;
}

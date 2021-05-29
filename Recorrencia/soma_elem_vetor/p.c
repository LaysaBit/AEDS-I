#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vetor[6], j=0, soma=0, a;

int somatorio(int k){
    if(j == a-1)
        return soma;
    soma += k;
    ++j;
    return somatorio(vetor[j]);
}
int main (){
    a = sizeof(vetor);
    for(int i = 0; i < a ; ++i)
        scanf("%d", &vetor[i]);

    printf("%d\n", somatorio(vetor[0]) );

    return 0;
}
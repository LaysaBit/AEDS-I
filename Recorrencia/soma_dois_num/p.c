#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int somatorio=0;
int soma(int maior, int menor){
    somatorio += maior;
    
    if( menor > 1 )
        return soma(maior,menor-1);
    if( menor == 1 )
        return somatorio;
}
int main (){
    int n, k;
    scanf("%d%d", &n, &k);

    if( n>=k )
        printf("%d\n", soma(n,k) );    
    else
        printf("%d\n", soma(k,n) );

    return 0;
}
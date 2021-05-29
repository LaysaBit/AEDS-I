#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int fatorialDuplo(int n){
    if(n-2 == 1)
        return n;  
    n = n*fatorialDuplo(n-2);
}
int main (){
    int n, result;
    scanf("%d", &n);
    
    result = fatorialDuplo(n);
    printf("%d\n", result);
    return 0;
}
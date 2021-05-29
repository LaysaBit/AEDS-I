#include <stdio.h>
#include <stdlib.h>

int main (){
    int a = 1, *b = NULL, **c = NULL, ***d = NULL;
    b = &a;
    c = &b;
    d = &c;
    
    (*b) = a*2;
    printf("%d\n", *b);
    
    (**c) = ((**c)*3)/2;
    printf("%d\n", **c);
    
    (***d) = ((***d)*4)/3;
    printf("%d\n", ***d);

    return 0;
}
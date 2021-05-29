#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char num[25];
int a, b;

int i = 0;
int swap(char *p){
    if (i == b || a == 1)
        return 0;
    else{
        char *q = &num[(a-1)-i];
        char tmp = *p;
        *p = *q;
        *q = tmp;
    }
    ++i;
    return (swap(&num[i]));
}
int main () {
    scanf(" %s", num);
    
    a = strlen(num);
    b = a/2;
    
    swap(&num[0]);
    
    printf("%s\n", num);
    return 0;
}
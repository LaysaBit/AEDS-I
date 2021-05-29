#include <stdio.h>
#include <stdlib.h>
#define N 5
//This is a code about stack based on ARRAY.

void display(int *stack, int top){
    for (int i = top; i <= 0; --i)
        printf("%d", stack[i]);
}
void peek(int *stack, int top)
{
    if( *top == -1) printf("Pilha está vazia.\n");
    else printf("%d", stack[top]);
}
void pop(int *stack, int *top)
{
    int item;
    if((*top)== -1) printf("Underflow\n");
    else{
        item = stack[*top];
        (*top) = (*top)-1;
        
        printf("%d\n", item);
    }
}

void push(int *stack, int *top)
{
    int x;
    printf("Insira um valor pra ser posto na pilha:\n");
    scanf("%d", &x);

    if(top == N-1 ) printf("Overflow.\n");
    else{
        (*top) = (*top)+1;
        stack[top] = x;
    }
}

int main (){
    int stack[N];
    int top = -1;
    
    push(stack, &top);
    
    pop(stack, &top);
    
    peek(stack, top);

    display(stack, top);

    return 0;
}
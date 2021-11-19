#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ISSO É UM PROGRAMA SOBRE CONJUNTOS DISJUNTOS COM PATH COMPRESSION E UNIAO USANDO RANK.

typedef struct tree { 
    int parent[100];
    int rank[100];
} tree;
int isInSet(int value, tree * arvore){
    if( arvore->parent[value] == -1)   return 0;
    else return 1;
}
void print(tree *arvore)
{
    int a = sizeof(arvore->parent)/sizeof(arvore->parent[0]);
    for(int i = 0; i < a; ++i ){
        if( arvore->parent[i] != -1)
            printf("Representante:%d, valor do conjunto:%d\n", arvore->parent[i], i);
    }
}
int findSet( int x, tree *arvore )
{
    while( x != arvore->parent[x] )
        x = findSet( arvore->parent[x], arvore); //estudar isso aqui
    
    return arvore->parent[x];
}
void makeSet(int vertice, tree *arvore)
{
    arvore->parent[vertice] = vertice;
    arvore->rank[vertice]  = 0;
}
void initVert(int nv, tree *arvore, int choice){
    int vertice;
    for (int i = 0; i < nv; ++i){
        if (choice == 4) printf("Diga um valor para o vértice.\n");
        scanf("%d", &vertice);
        makeSet(vertice, arvore);
    }
}
void unionByRank(int x, int y, tree *arvore){
    int rx = findSet(x, arvore);
    int ry = findSet(y, arvore);
    
    if ( rx == ry ) 
        return;

    if( arvore->rank[rx] > arvore->rank[ry] )
        arvore->parent[ry] = rx;
    else{
        arvore->parent[rx] = ry;
        if (arvore->rank[rx] == arvore->rank[ry])
            arvore->rank[ry] = arvore->rank[ry] + 1;
    }
}
void initEdges(int ne, tree *arvore, int choice){
    int edge1, edge2, result1, result2;

    for (int i = 0; i < ne; ++i){
        if (choice == 3) printf("Insira dois valores para os vértices\n");
        scanf("%d %d", &edge1, &edge2);
        
        result1 = isInSet(edge1, arvore); //Analisar se já é um vértice isolado.
        result2 = isInSet(edge2, arvore);

        if(!result1) makeSet(edge1, arvore); //Se nao for vertice isolado, faça-o ser.
        if(!result2) makeSet(edge2, arvore);
        
        unionByRank(edge1, edge2, arvore);
    }
}
int main (){
    int choice, value, nv, ne, vertice, result;
    tree arvore;
    
    memset(arvore.parent, -1, sizeof(arvore.parent));
    memset(arvore.rank, -1, sizeof(arvore.rank));
    
    printf("Quantos vertices vai ter o conjunto?\n");
    scanf("%d", &nv);
    initVert(nv, &arvore, 0);

    printf("Quantas arestas vai ter o conjunto?\n");
    scanf("%d", &ne);
    initEdges(ne, &arvore, 0);
    
    while(1){
        printf("1 - Voce deseja visualizar os conjuntos?\n");
        printf("2 - Gostaria de achar algum elemento?\n");
        printf("3 - Voce deseja fazer outra aresta?\n");
        printf("4 - Gostaria de adicionar outro vertice?\n");
        printf("5 - Voce quer encerrar aqui?\n");
        scanf("%d", &choice);
        if(choice == 1)  print(&arvore);
        else if(choice == 2){
            printf("Que elemento voce deseja achar?\n");
            scanf("%d", &value);
            result = isInSet(value, &arvore);
            if(!result) printf("Nao esta contido em nenhum conjunto.\n");
            if(result)  printf("%d esta no conjunto do representante %d\n", value, arvore.parent[value] );
        }
        else if(choice == 3) initEdges(1, &arvore, choice);
        else if(choice == 4) initVert(1, &arvore, choice);
        else if(choice == 5) return 0;
    }
    
   return 0;
}

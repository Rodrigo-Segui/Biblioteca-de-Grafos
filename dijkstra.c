

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "dijkstra.h"
#include <limits.h>
#include <stdbool.h>


void dijkstra(Grafo *g,Heap **heap){
    int VerticeInicial;
    Nodo *V;
    Aresta *AResta;
    int x,v,u,t=1;
    Heap r;
    printf("Digite Vertice Inicial: ");
    scanf("%d",&VerticeInicial);
    
    int *distancia=(int*)malloc(sizeof(int)*g->tamanho);//vetor de diastancia
    int *predecessor=(int*)malloc(sizeof(int)*g->tamanho);//vetor de predecessor
    bool aberto[g->tamanho];//vetor vertice esta aberto
        
        for(int i=1;i<=g->tamanho;i++)//inicializacao dos vetores
        {
            predecessor[i]=-1;
            distancia[i]=INT_MAX/2;
            aberto[i]=true;
        }

    distancia[VerticeInicial]=0;
    V=BuscaNodo(g,VerticeInicial);//busca vertice inicial
        if(V!=NULL){//se vertice existir
            AResta=V->adj;
                while(AResta!=NULL){//enquanto vertice ter adj insere-as na heap
                    t=buildHeap(heap,t,AResta);
                    AResta=AResta->prox;
                }
        }
    t--;

while(t>0){//enquanto tamanho da heap ser maior que zero repete
     r=getRaiz(heap);//pega raiz
     t=deleteHeap(heap,t);
    v=r.chave_adj;
    u=r.chave_partida;
       if(distancia[v] > distancia[u]+r.peso){//se distancia para chegar do vertice ser maior 
            distancia[v]=distancia[u]+r.peso;//que a nova distancia troca
            predecessor[v]=u;
            V=BuscaNodo(g,r.chave_adj);//busca vertice encontrado
            t++;
                if(V!=NULL){
                    AResta=V->adj;
                        while(AResta!=NULL){
                            t=buildHeap(heap,t,AResta);//insere na heap arestas ligadas ao nodo
                            AResta=AResta->prox;
                        }
                }
        }

t--;
}


for(x=1;x<=g->tamanho;x++){
  
    printf("%d\t ",x);

}

printf("\n");
for(x=1;x<=g->tamanho;x++){
  
    printf("%d\t ",distancia[x]);

}
printf("\n");
}


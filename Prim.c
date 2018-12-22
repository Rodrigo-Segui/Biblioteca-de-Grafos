
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "conjuntos.h"
#include "heap.h"
#include "Prim.h"

void Prim(Grafo *g,Heap **heap){
        int *conjunto;
        int VerticeInicial,Tamanho=1,NodoPartida,NodoSaida;
        Heap Raiz;
        int y;
        Aresta *ArestA;
        Nodo *Vertice;
        conjunto=makeSet(g->tamanho);
       
        printf("Digite Vertice Inicial: ");
        scanf("%d",&VerticeInicial);
        Vertice=BuscaNodo(g,VerticeInicial);//busca vertice inicial
                if(Vertice!=NULL){//se vertice existir
                        ArestA=Vertice->adj;
                        while(ArestA!=NULL){//enquanto vertice ter adj insere na heap
                        Tamanho=buildHeap(heap,Tamanho,ArestA);
                        ArestA=ArestA->prox;
                        }
                }
       Tamanho--;
       
        while(Tamanho>0){//repete enquanto tamanho da heap se maior que zero
                Raiz=getRaiz(heap);//pega raiz
                Tamanho=deleteHeap(heap,Tamanho);//delete
                NodoPartida=findset(conjunto,Raiz.chave_partida);
                NodoSaida=findset(conjunto,Raiz.chave_adj);
                        if(NodoPartida!=NodoSaida){//verifica se vertices fazem parte do mesmo conjunto
                        printf("%i,",Raiz.chave_partida);
                        printf("%i,",Raiz.chave_adj);
                        printf("%i",Raiz.peso);
                        printf("\n");
                        conjunto=unio(conjunto,NodoSaida,NodoPartida);//une vertices um conjunto
                        Vertice=BuscaNodo(g,Raiz.chave_adj);//busca novo vertice conhecido
                        Tamanho++;
                                if(Vertice!=NULL){//se vertice existir
                                ArestA=Vertice->adj;
                                        while(ArestA!=NULL){//enquanto existir arestas
                                                Tamanho=buildHeap(heap,Tamanho,ArestA);//insere na heap
                                                 ArestA=ArestA->prox;
                                        }
                                }
                        }
        Tamanho --;  
             
        }

}
                       
                
                       


            
 
      














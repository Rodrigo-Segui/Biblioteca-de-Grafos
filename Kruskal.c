//created by Rodrigo Segui 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "conjuntos.h"
#include "heap.h"
#include "Kruskal.h"

void Kruskal(Grafo *g,Heap **heap){
        Heap raiz;//recebe aresta raiz
        int *conj;
        conj=makeSet(g->tamanho);//inicializa conjDij
        int tamanho=1;
        int VerticePartida,VerticeSaida;
            //INSERIR NO HEAP
        Nodo *vertice;
        Aresta *aresta;
        vertice=g->lista_nodo;//Vertices
                while(vertice!=NULL){//enquanto existirem vertices
                aresta=vertice->adj;
                        while(aresta!=NULL){//enquanto existirem arestas
                        tamanho=buildHeap(heap,tamanho,aresta);//insere arestas na heap
                        aresta=aresta->prox;
                        }
                vertice=vertice->prox;
                }
        tamanho --;
        
        while(tamanho>0){
                raiz=getRaiz(heap);//pega raiz
                VerticePartida=findset(conj,raiz.chave_partida);
                VerticeSaida=findset(conj,raiz.chave_adj);
                        if(VerticePartida!=VerticeSaida){//verifica vertices nao fazem parte do mesmo conjunto
                        printf("%i,",raiz.chave_partida);
                        printf("%i,",raiz.chave_adj);
                        printf("%i",raiz.peso);
                        printf("\n");
                        conj=unio(conj,VerticeSaida,VerticePartida);//une os vertices em um conj
                        }
                tamanho=deleteHeap(heap,tamanho);//deleta aresta da heap
        }

}

       
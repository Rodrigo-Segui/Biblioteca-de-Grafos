//created by Rodrigo Segui 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dfs.h"


Pilha *CriaPilha(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    p->topo=NULL;
    p->quantidade=0;
    return p;
}

Pilha *Push(Pilha *p,int v){
    Lista *novo=(Lista*)malloc(sizeof(Lista));
    novo->NumberNodo=v;
    novo->prox=p->topo;
    p->topo=novo;
    p->quantidade++;
    return p;
}

int Pop(Pilha *p){
    Lista *temp;
    int v;
        if(p->topo!=NULL){
        temp=p->topo;
        v=temp->NumberNodo;
        p->topo=temp->prox;
        free(temp);
        p->quantidade--;
        return v;
        }
        }

void PrintaVetor(int tam,int *vet){
    int y;
        for(y=1;y<=tam;y++){
        printf("%d ",y);
        }
    printf("\n");
        for(y=1;y<=tam;y++){
        printf("%d ",vet[y]);
        }
    printf("\n");
}

int BuscaPilha(Pilha *p,int chave){
    Lista* q;
    int i=1;
        for(q=p->topo;q!=NULL;q=q->prox){
            if(q->NumberNodo==chave){
            i++;
            }
        }
        return i;//retorna 1 se nao estive na pilha
}



void dfs(int nodo,Grafo *g){
    int tam,i=0,visitado=1,u,n,z=0,j;
    int x=1;
    Pilha *p=CriaPilha();
    int a;
    int vet[g->tamanho];//vetor tamanho nodos
    int solucao[g->tamanho];
        for (u=1;u<=g->tamanho;u++){
            solucao[u]=0;
            vet[u]=0;//inicializa cada posicao com zero
        }
    
    Nodo *w=BuscaNodo(g,nodo);//busca nodo no grafo
    vet[nodo]=visitado; 
    solucao[x++]=nodo; 
    if(w!=NULL){
    Aresta *k=w->adj;
        for(k;k!=NULL;k=k->prox){
       //enquanto nodo inicial tem adj push pilha
        p=Push(p,k->chave_adj);
        }
    }

        while(p->quantidade>0){ //enquanto qtd da pilha ser maior que zero-> POP
            n=Pop(p);
                if(vet[n]==0){ 
                solucao[x]=n;
                x++;
                vet[n]=visitado;
                Nodo *x=BuscaNodo(g,n);
                    if(x!=NULL){
                    Aresta *q=x->adj;
                        for(q;q!=NULL;q=q->prox){   //se encontrei//enquanto existir adj
                        z=BuscaPilha(p,q->chave_adj); //retorna 1 se nao estiver na pilha
                            if(z==1){
                            p=Push(p,q->chave_adj);
                            }
                        }
                    }
                }
        }

       
        PrintaVetor(g->tamanho,solucao);
}



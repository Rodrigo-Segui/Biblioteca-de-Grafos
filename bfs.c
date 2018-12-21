//created by Rodrigo Segui 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "bfs.h"

Fila* fila_cria(){
	Fila*f=(Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = NULL; //
	return f;
}


void PrintaVetorf(int tam,int *vet){
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

void fila_insere(Fila*f,float v){
	ListaF*novo=(ListaF*)malloc(sizeof(ListaF));
	novo->info=v;
	novo->prox=NULL;
	if(f->fim==NULL&&f->ini==NULL){
		f->ini=novo;
		f->fim=novo;
	}
	else{
		f->fim->prox=novo;
		f->fim=novo;
	}
}
float fila_retira(Fila*f){
		ListaF*t;
		float v;
		if(f->fim==NULL&&f->ini==NULL)
		{
			
			printf("Fila vazia!\n");
		exit(0);
		}
		t=f->ini;
		v=t->info;
		f->ini=t->prox;
		if(f->ini==NULL)
		f->fim=NULL;
		free(t);
		return v;
	}




	 void imprimir_fila(Fila*f){
   	{
   		ListaF*q;
		   
   		for(q=f->ini;q!=NULL;q=q->prox)
   		{
			   
		   		printf("%.2f\n",q->info);
	}
			   }
		   }

 

void bfs(int nodo,Grafo *g){
    int tam,i=0,Visitado=1,u,n,z=0,x=1,j;
    Fila *f=fila_cria();
    int vetor[g->tamanho]; 
    int solucao[g->tamanho];
    Nodo *v;
    Aresta *m;
        for (u=1;u<=g->tamanho;u++){
            vetor[u]=0;
            solucao[u]=0;
            }
      
    v=BuscaNodo(g,nodo);
    vetor[nodo]=Visitado;
    solucao[x]=nodo;
    x++;
        if(v!=NULL){// verifica se vertice existe
           m=v->adj;
                while(m!=NULL){//enquanto possuir adjacencia
                fila_insere(f,m->chave_adj);//insere na fila
                m=m->prox;
                }
        }
      
        while(f->ini!=NULL){//enquanto fila nao estiver vazia
        n=fila_retira(f);//retira fila
            if(vetor[n]==0){//verifica se nodo nao foi visitado
            vetor[n]=Visitado;//visita
            solucao[x]=n;
            x++;
            v=BuscaNodo(g,n);//busca nodo
                if(v!=NULL){//
                m=v->adj;
                    while(m!=NULL){//enquanto possuir adjacencias
                    fila_insere(f,m->chave_adj);//insere na fila
                    m=m->prox;
                    }
                }
            }
        }
                            
    PrintaVetorf(g->tamanho,solucao);
}



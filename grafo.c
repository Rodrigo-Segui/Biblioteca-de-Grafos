//created by Rodrigo Segui
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

    Grafo *CriaGrafo(int tamanho)
{
    Grafo *g=(Grafo*)malloc(sizeof(Grafo));//alocacao dinamica
    g->tamanho=tamanho;//tamanho linha 1 grafo.txt
    g->lista_nodo=NULL;//lista vazia

    return g;
}


Nodo *CriaNodo(int chave1)
{
    Nodo *novo=(Nodo*)malloc(sizeof(Nodo));//aloca novo vertice
    novo->chave=chave1;//insere chave vertice
    novo->adj=NULL;
    novo->prox=NULL;
    return novo;//retorna vertice criado

}
int BuscaVerticeExiste(Grafo *g,int chave1)
{
int n=0;
  Nodo *aux=g->lista_nodo;
        while(aux!=NULL){
            if(aux->chave==chave1){// incrementa n++ se vertice ja existir
            n++;}
            aux=aux->prox;
                        }
            return n;//retorna zero se vertice nao existir

}



    Grafo *InsereNodo(Grafo *g,int chave1)
{
int x;
x=BuscaVerticeExiste(g,chave1);//retorna zero se vertice nao existir
//cria a lista encadeada de nodos
if(x==0){
Nodo *novoNodo = CriaNodo(chave1);//retorna nodo criado
		if(g->lista_nodo == NULL){//insere no inicio
			g->lista_nodo = novoNodo;

            }
        else{
            Nodo *temp = g->lista_nodo;//insere no final
                while(temp->prox!=NULL){
					temp = temp->prox;
                }
			temp->prox = novoNodo;
		}
		}
	return g;//retorna grafo com vertice inserido

}

Aresta *CriaAdj(int chave1,int chave2,int peso)
{
    Aresta *temp=(Aresta*)malloc(sizeof(Aresta));//aloca dinamicamente
    temp->chave_adj=chave2;//insere chave aresta
    temp->peso=peso;//insere peso
    temp->chave_partida=chave1;
    temp->prox=NULL;

    return temp;//retorna aresta
}


Nodo *BuscaNodo(Grafo *g,int chave1)
{
    Nodo *tempo=g->lista_nodo;
        while(tempo!=NULL){//
            if(tempo->chave==chave1){//encontra vertice que liga a aresta
            return tempo;}
            tempo=tempo->prox;
                        }
            return NULL; 
}


Grafo *InsereAresta(Grafo *g,int chave1,int chave2,int peso)
{

        Nodo *nodosaida=BuscaNodo(g,chave1);//retorna vertice
            if(nodosaida==NULL){
                printf("Nodo buscado nao existe");
                    return g;
                                }
        Aresta *novo=CriaAdj(chave1,chave2,peso);//retorna aresta criada
            if(nodosaida->adj==NULL){////insere no inicio
                nodosaida->adj=novo;
                                    }
            else{
                Aresta *aux=nodosaida->adj;
                    while(aux->prox!=NULL)//
                    {
                        aux=aux->prox;
                    }
                        aux->prox=novo;//insere no final
                }

                        return g;//RETORNA GRAFO COM ARESTA INSERIDA
}

Grafo *le_txt()
{
FILE *arquivo;
int chave1,chave2,peso;
    int i=0;
    int tam=0,x=0;
    char y[1000000];
    char z;
    arquivo=fopen("grafo.txt","r");
    fscanf(arquivo,"%d",&tam);
    Grafo *g=NULL;
    g=CriaGrafo(tam);//retorna grafo criado
    while((z=fgetc(arquivo))!=EOF){
if(z!='\n'){//le caractere po caractere
y[x]=z;
x++;
}else{
y[x]='\0';
if(x>0){
chave1=atoi(strtok(y,";"));//trtok pegar chave1
chave2=atoi(strtok(NULL,";"));//sstrotok pegar chave2
peso=atoi(strtok(NULL,";")); //strtok pegar pes
g=InsereNodo(g,chave1); //retorna o grafo att com novo vertice
g=InsereAresta(g,chave1,chave2,peso);//retorna o grafo att com nova aresta
}
x=0;
y[x]='\0';
}
}
return g;
fclose(arquivo);
}

    void imprimi(Grafo *g){
    for (Nodo *n  = g->lista_nodo; n != NULL ; n = n->prox) {
        printf("[%d] ->", n->chave);
        for (Aresta *a = n->adj; a != NULL ; a = a->prox) {
            printf(" %d->",a->chave_adj);
        }

        printf("\n");
    }
}













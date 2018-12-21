//created by Rodrigo Segui 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"


//Alloca a heap (vetor de structs) com nova aresta,
//insere o nova ao aresta e chama a percolate para organizar a heap;

int buildHeap(Heap **heap,int tamanho, Aresta *aresta){
    Aresta *m=aresta;
    heap[tamanho-1]=NULL;
	heap[tamanho-1]=(Heap*)(malloc(sizeof(Heap)));
	heap[tamanho-1]->chave_partida=m->chave_partida;
	heap[tamanho-1]->peso=m->peso;
	heap[tamanho-1]->chave_adj=m->chave_adj;
if(tamanho>1){
percolate(heap,tamanho);
}
tamanho ++;
return tamanho;
}

//função percolate para posicionar as aresta pelo peso na heap apos insercoes
void percolate(Heap **heap,int tamanho){
	int aux,auxch1,auxch2;
	int i=tamanho-1;
		for(i;i!=0;i--){
			if(heap[i]->peso < heap[i-1]->peso){//ordena pelo peso
			auxch1=heap[i]->chave_partida;//
			auxch2=heap[i]->chave_adj;
			aux=heap[i]->peso;//
			heap[i]->peso=heap[i-1]->peso;//
			heap[i-1]->peso=aux;//
			heap[i]->chave_adj=heap[i-1]->chave_adj;
			heap[i-1]->chave_adj=auxch2;
			heap[i]->chave_partida=heap[i-1]->chave_partida;//
			heap[i-1]->chave_partida=auxch1;//
}
    }
        }

//funcao retorna a raiz
Heap getRaiz(Heap **heap){
    Heap aux;
	aux.peso=heap[0]->peso;
	aux.chave_adj=heap[0]->chave_adj;
	aux.chave_partida=heap[0]->chave_partida;
	return aux;//retorna raiz
}

//função sift-down para posicionar apos o delete as arestas pelo peso da heap
void siftDown(Heap **heap,int tamanho){
    int i;
	int aux,auxc1,auxc2;
		for(i=0;i<tamanho-1;i++){
			if(heap[i]->peso > heap[i+1]->peso){//ordena pelo peso
			aux=heap[i+1]->peso;
			auxc1=heap[i+1]->chave_adj;
			auxc2=heap[i+1]->chave_partida;
			heap[i+1]->peso=heap[i]->peso;
			heap[i+1]->chave_adj=heap[i]->chave_adj;
			heap[i+1]->chave_partida=heap[i]->chave_partida;
			heap[i]->peso=aux;
			heap[i]->chave_adj=auxc1;
			heap[i]->chave_partida=auxc2;

		}
	}	
}

//função para deletar arestas da heap
//Retira a aresta raiz, copia a última aresta para a raiz, realoca a área de memória 
//Chama a siftdown para reorganizar as arestas.
int deleteHeap(Heap **heap,int tamanho){
		heap[0]->chave_adj=heap[tamanho-1]->chave_adj;
		heap[0]->chave_partida=heap[tamanho-1]->chave_partida;
		heap[0]->peso=heap[tamanho-1]->peso;
		free(heap[tamanho-1]);
		tamanho--;
siftDown(heap,tamanho);
return tamanho;
}







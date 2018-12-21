
//created by Rodrigo Segui 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dfs.h"
#include "bfs.h"
#include "heap.h"
#include "Kruskal.h"
#include "Prim.h"
#include "dijkstra.h"

        int main(){
int op;
Grafo *g;
int nbfs;
int ndfs;
int op1;
int t=1;
Heap **heap;
	int i,k;
	do{
printf("Escolha opcao abaixo: \n");
printf("|1| Ler Parser.\n");
printf("|2| Imprimir Grafo.\n");
printf("|3| Busca DFS.\n");
printf("|4| Busca BFS.\n");
printf("|5| Kruskal.\n");
printf("|6| Prim.\n");
printf("|7| Dijkstra.\n");
printf("|0| Sair\n");
printf("Opcao: ");
scanf("%d",&op);
printf("\n");
switch(op)
	{
		case 1:
g=le_txt();
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;
		case 2:
        imprimi(g);
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;
		case 3:
		printf("Digite Nodo para comecar Busca em Profundidade (DFS): ");
		scanf("%d",&ndfs);
        dfs(ndfs,g);
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;
		case 4:
		printf("Digite Nodo para comecar Busca em Largura (BFS): ");
		scanf("%d",&nbfs);
		bfs(nbfs,g);
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;
		case 5:
		Kruskal(g,heap);
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;


        case 6:
		Prim(g,heap);
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;

		case 7: 

	dijkstra(g,heap);
printf("\nPressione enter para continuar...\n");
getchar();
getchar();
break;

}
		}while(op!=0);

		return 0;
}

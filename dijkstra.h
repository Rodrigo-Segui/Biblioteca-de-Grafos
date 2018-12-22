
#include <stdbool.h>

void dijkstra(Grafo *g,Heap **heap);
void Relaxa(Grafo *g,int *predecessor,int *distancia,int u, int v);
int menorDist(Grafo *g,bool *aberto,int *distancia);
//bool existeAberto(Grafo *g,int *aberto);
bool existeAberto(Grafo *g,bool *aberto);
 

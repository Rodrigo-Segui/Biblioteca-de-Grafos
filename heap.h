
//Biblioteca Heap

typedef struct heap{
int chave_partida;
int peso;
int chave_adj;
}Heap;

//função que constroi um novo heap com a aresta inserida
int buildHeap(Heap **heap,int tamanho, Aresta *m);

//função para deletar aresta da heap
int deleteHeap(Heap **heap,int tamanho);

//função sift-down para posicionar os arestas da heap
void siftDown(Heap **heap,int tamanho);

//função percolate para posicionar os arestas da heap
void percolate(Heap **heap,int tamanho);

//retorna a raiz da heap
Heap getRaiz(Heap **heap);

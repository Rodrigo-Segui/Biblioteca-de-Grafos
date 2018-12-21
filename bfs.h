
struct listaf{
	float info;
	struct listaf*prox;
};typedef struct listaf ListaF;

struct fila {
	ListaF*ini;
	ListaF*fim;
};typedef struct fila Fila;

Fila* fila_cria();
void fila_insere(Fila*f,float v);
float fila_retira(Fila*f);
void fila_libera(Fila*f);
void imprimir_fila(Fila*f);
void bfs(int nodo,Grafo *g);
int BuscaFila(Fila *f,int chave);
void PrintaVetorf(int tam,int *vet);
void printafila(Fila *f);

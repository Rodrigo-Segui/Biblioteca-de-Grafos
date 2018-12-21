

struct lista{
int NumberNodo;
struct lista *prox;
};typedef struct lista Lista;

struct pilha{
int quantidade;
Lista *topo;
};typedef struct pilha Pilha;


void dfs(int nodo,Grafo *g);
Pilha *CriaPilha();
Pilha *Push(Pilha *p,int v);
int Pop(Pilha *p);
int BuscaPilha(Pilha *p,int chave);
void PrintaVetor(int tam,int *vet);

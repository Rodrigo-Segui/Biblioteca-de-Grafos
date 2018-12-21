//created by Rodrigo Segui 
struct aresta{
int chave_adj;
struct aresta *prox;
int chave_partida;
int peso;
};typedef struct aresta Aresta;


struct nodo{
int chave;
struct nodo *prox;
Aresta *adj;
};typedef struct nodo Nodo;


struct grafo{
Nodo *lista_nodo;
int tamanho;//numero de vertices
};typedef struct grafo Grafo;


Grafo *CriaGrafo(int tamanho);
int BuscaVerticeExiste(Grafo *g,int chave1);
Nodo *CriaNodo(int chave1);
Grafo *InsereNodo(Grafo *g,int chave1);
Grafo *le_txt();
Aresta *CriaAdj(int chave1,int chave2,int peso);
Grafo *InsereAresta(Grafo *g,int chave1,int chave2,int peso);
Nodo *BuscaNodo(Grafo *g,int chave1);
void imprimi(Grafo *g);


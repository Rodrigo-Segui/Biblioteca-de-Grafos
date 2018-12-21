INDEX:
	gcc -c main.c -g
	gcc -c grafo.c -g 
	gcc -c bfs.c -g 
	gcc -c dfs.c -g 
	gcc -c conjuntos.c -g 
	gcc -c heap.c -g 
	gcc main.o grafo.o dfs.o bfs.o heap.o conjuntos.o -o main 
	
	



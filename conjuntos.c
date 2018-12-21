//created by Rodrigo Segui 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "conjuntos.h"


int *makeSet(int n){
int *conj=(int*)calloc(n,sizeof(int));
int i;
	for(i=1;i<n+1;i++){
		conj[i]=i;
					  }
	
	for(i=1;i<n+1;i++){
					  }
		return conj;
}

int findset(int *conj,int i){
	if(conj[i]==i)
{
	return i;
}else{
	conj[i]=findset(conj,conj[i]);
	return conj[i];
	 }
	}

int *unio(int *conj,int i,int j){
	conj[i]=findset(conj,j);



return conj;
}

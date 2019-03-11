#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
struct arvore{
	int n;
	struct arvore *esq;
	struct arvore *dir;
};
arv cria(){
	printf("Arvore criada\n");
	return NULL;
}
int vazia(arv a){
	if(a==NULL)return 0;
	else return 1;
}
int dados(){
	int val;
	printf("valor: ");scanf("%d",&val);
	return val;
}
arv ins(arv a,int val){
	if(vazia(a)==0){
		a=(arv)malloc(sizeof(arv));
	a->dir=NULL;a->esq=NULL;a->n=val;return a;
	}else{
		if(val==a->n){
			printf("ja contem este valor\n");
		}
	else if(val<a->n){
			a->esq=ins(a->esq,val);
		}else{
			a->dir=ins(a->dir,val);
		}
	}return a;
}
void busca(arv a,int val){
	if(vazia(a)!=0){
	if(val==a->n)printf("%d encontrado\n",val);
		else if(val<a->n){
			busca(a->esq,val);
		}else if(val>a->n){
			busca(a->dir,val);
		}else return ;
}}
int altura(arv a){
	if(a==NULL)return -1;
	else{
		int e=altura(a->esq);
		int d=altura(a->dir);
		if(e<d)return d+1;
		else return e+1;
	}
}
arv remo(arv a,int v){
	if(a==NULL)return a;
	else if(v<a->n){
		a->esq=remo(a->esq,v);
	}else if(v>a->n){
		a->dir=remo(a->dir,v);
	}else{
		if(a->dir==NULL&&a->esq==NULL){
			free(a);a=NULL;	
		}else if(a->esq==NULL){
			arv b=a;a=a->dir;
			free(b);
		}else if(a->dir==NULL){
			arv b=a;a=a->esq;
			free(b);
		}else{
			arv b=a->dir;
			a->n=b->n;
			a->dir=remo(a->dir,b->n);
		}
	}return a;
}
void prefes(arv a){
	if(vazia(a)!=0){
		printf("(");
		printf("%d",a->n);
		prefes(a->esq);
		prefes(a->dir);
		printf(")");
	}
}
void cenesq(arv a){
	if(a!=NULL){
		cenesq(a->esq);
		printf("%d, ",a->n);
		cenesq(a->dir);
	}
}
void posfes(arv a){
	if(a!=NULL){
		posfes(a->esq);
		posfes(a->dir);
		printf("%d, ",a->n);
	}
}
arv libera(arv a){
	if(vazia(a)!=0){
		libera(a->esq);
		libera(a->dir);
		free(a);
	}return NULL;
}

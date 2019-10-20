#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#include "fila.h"
/*
Gerenciar as vendas realizadas. 
Para cada venda registrar o cpf do comprador,
data da venda, 
os produtos escolhidos,
a quantidade de cada um e o valor total. 
*/

typedef struct lista listaprodutos;
struct lista{
	int cpf;
	struct dt_venda data;
	struct prod produtos;
	int valorTotal;
	listaprodutos* prox;
};
struct fila{
	listaprodutos* ini;
	listaprodutos* fim;
};
fila* fila_cria(){
	fila* f = (fila*) malloc(sizeof(fila));
	f->ini = f->fim = NULL;
	return f;
}
void fila_insere(fila* f, float v){
	listaprodutos* n = (listaprodutos*) malloc(sizeof(listaprodutos));
	n->infor = v;
	n->prox = NULL;
	if(f->fim != NULL)
		f->fim->prox = n;
	else{
		f->ini = n;
	}
	f->fim = n;
}
float fila_retira(fila* f){
	listaprodutos* t = f->ini;
	f->ini = t->prox;
	if(f->ini == NULL){
		f->fim = NULL;
	}
	free(t);
	return v;
}
int fila_vazia(fila* f){
	return (f->ini==NULL);
}
void fila_libera(fila* f){
	listaprodutos* q = f->ini;
	while(q!=NULL){
		listaprodutos* t = q->prox;
		free(q);
		q = t;
	}
	free(t);
}
void fila_imprime(Fila* f){
	for(listaprodutos* q=f->ini; q!=NULL;q=q->prox){
		printf("%f\n",q->infor);
	}
}
int main(){
	Fila* f = fila_cria();
	fila_insere(f);
	fila_insere(f);
	fila_insere(f);
	printf("Primeiro elemento: %f\n",fila_retira(f));
	printf("Segundo elemento: %f\n",fila_retira(f));
	fila_imprime(f);
	fila_libera(f);
return 0;
}


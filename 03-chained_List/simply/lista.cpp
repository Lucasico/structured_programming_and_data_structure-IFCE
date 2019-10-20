#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
struct lista{
	int info;
	struct lista* prox;
};
/*
	O tipo Lista representa um nó da lista
	e a estrutura de lista encadeada é representada
	pelo ponteiro para seu primeiro elemento(tipo Lista)
*/
typedef struct lista Lista;
//função de inicialização: retorna uma lista vazia
Lista* inicializa(){
	return NULL;
}
//função para verificar se a lista esta vazia
int vazia(Lista* l){
	if(l != NULL){
		return 1;
	}else{
		return 0;
	}
}
//função de inserção no inicio da lista
//insere no início: retorna a lista atualizada
Lista* insere(Lista* l, int i){

	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	
	return novo;	
}
/*
Função para percorrer e exibir os elementos da lista
*/
void imprimir(Lista* l){
	Lista *a;//variavel aux
	int contNo = 0;
	/*
		a inicializa em l, repete até a == vazio, a recebe a para o proximo nó
	*/
	for(a = l; a != NULL; a = a->prox){
		contNo++;
		printf("Informação referente ao %dº Nó: %d\n",contNo,a->info);
	}
}
/*
Função de busca de elementos na lista
*/
Lista* busca(Lista* l, int busca){
	Lista* a;//variavel aux
	for(a = l; a != NULL; a = a->prox){
		if(a->info == busca){
			return a;
		}
	}
	return NULL;
}
/*
Função retira: retira elemento da lista
*/
Lista* retira (Lista* l, int v) {   Lista* ant = NULL;
 Lista* p = l;      
    while (p != NULL && p->info != v) {   
	   ant = p;      p = p->prox;  
	}
    if (p == NULL)    
	  return l;   /* não achou: retorna lista original */
   if (ant == NULL) {    
     /* retira elemento do inicio */    
	  l = p->prox;   
	}else
	{
		ant->prox = p->prox;   
	}  
	 free(p);  
	  return l; 
}

/*
Função auxiliar: cria e inicializa um nó
*/
Lista* cria(int v){
	
	Lista *p = (Lista*)malloc(sizeof(Lista));
	p->info = v;
	return p;
}
Lista* insere_meio(Lista* l, int v){
	Lista* novo = cria(v);
	Lista* ant = NULL;
	Lista* p = l;
	
}
/*
Função para libera o espaço alocado
*/
void libera(Lista* l){
	Lista* p = l;
	while(p != NULL){
		Lista* t = p->prox;//guarda refererncia para o prox elemento
		free(p);//libera a memoria apontada por p
		p = t;//faz p apontar para o próximo
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	int verifica,b;
	Lista* l;//declara uma lista não inicializada
	
	l = inicializa();//inicializa lista como vazia
	
	l = insere(l,23);//insere na lista o elemento 23, no inicio
	
	l = insere(l,45);//insere na lista o elemento 45, no inicio
	
	l = insere(l,41);//insere na lista o elemento 41, no inicio
	
	l = insere(l,37);//insere na lista o elemento 37, no inicio
	l = insere(l,100);
	//cria();//função auxliar para criar o Nó
	//insere na lista o elemento 100, no meio/
	
	imprimir(l);//imprimir valores armazenados nos nós da lista 
	
	verifica = vazia(l);// verifica se esta vazia.
	printf("\n\nDigite um número que deseja busca na lista: ");
		scanf("%d",&b);
	Lista* recebe = busca(l,b);	
	if(recebe == NULL){
		printf("Valor não encontrado\n");
	}else{
		printf("Valor encontrado\n");
	}
	imprimir(l);	
	printf("\n\n");
	l = retira(l,10001);
	libera(l);
	
return 0;
}


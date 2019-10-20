#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
struct lista{
	int info;
	struct lista* prox;
};
/*
	O tipo Lista representa um n� da lista
	e a estrutura de lista encadeada � representada
	pelo ponteiro para seu primeiro elemento(tipo Lista)
*/
typedef struct lista Lista;
//fun��o de inicializa��o: retorna uma lista vazia
Lista* inicializa(){
	return NULL;
}
//fun��o para verificar se a lista esta vazia
int vazia(Lista* l){
	if(l != NULL){
		return 1;
	}else{
		return 0;
	}
}
//fun��o de inser��o no inicio da lista
//insere no in�cio: retorna a lista atualizada
Lista* insere(Lista* l, int i){

	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	
	return novo;	
}
/*
Fun��o para percorrer e exibir os elementos da lista
*/
void imprimir(Lista* l){
	Lista *a;//variavel aux
	int contNo = 0;
	/*
		a inicializa em l, repete at� a == vazio, a recebe a para o proximo n�
	*/
	for(a = l; a != NULL; a = a->prox){
		contNo++;
		printf("Informa��o referente ao %d� N�: %d\n",contNo,a->info);
	}
}
/*
Fun��o de busca de elementos na lista
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
Fun��o retira: retira elemento da lista
*/
Lista* retira (Lista* l, int v) {   Lista* ant = NULL;
 Lista* p = l;      
    while (p != NULL && p->info != v) {   
	   ant = p;      p = p->prox;  
	}
    if (p == NULL)    
	  return l;   /* n�o achou: retorna lista original */
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
Fun��o auxiliar: cria e inicializa um n�
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
Fun��o para libera o espa�o alocado
*/
void libera(Lista* l){
	Lista* p = l;
	while(p != NULL){
		Lista* t = p->prox;//guarda refererncia para o prox elemento
		free(p);//libera a memoria apontada por p
		p = t;//faz p apontar para o pr�ximo
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	int verifica,b;
	Lista* l;//declara uma lista n�o inicializada
	
	l = inicializa();//inicializa lista como vazia
	
	l = insere(l,23);//insere na lista o elemento 23, no inicio
	
	l = insere(l,45);//insere na lista o elemento 45, no inicio
	
	l = insere(l,41);//insere na lista o elemento 41, no inicio
	
	l = insere(l,37);//insere na lista o elemento 37, no inicio
	l = insere(l,100);
	//cria();//fun��o auxliar para criar o N�
	//insere na lista o elemento 100, no meio/
	
	imprimir(l);//imprimir valores armazenados nos n�s da lista 
	
	verifica = vazia(l);// verifica se esta vazia.
	printf("\n\nDigite um n�mero que deseja busca na lista: ");
		scanf("%d",&b);
	Lista* recebe = busca(l,b);	
	if(recebe == NULL){
		printf("Valor n�o encontrado\n");
	}else{
		printf("Valor encontrado\n");
	}
	imprimir(l);	
	printf("\n\n");
	l = retira(l,10001);
	libera(l);
	
return 0;
}


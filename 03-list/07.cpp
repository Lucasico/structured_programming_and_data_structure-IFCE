#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define TAM 10
typedef struct pessoa{
	char nome[20];
	int idade;
	float peso;
}pessoa;

pessoa contribuidores[TAM];
void quick_sort(pessoa *contribuidores,int inicio,int fim){
		int esq,dir,meio,pivo;
		pessoa aux;
	//limites da esquerda e da direita
	esq = inicio;
	dir = fim;
	//ajustando auxiliares do centro
	
	meio = (int)((esq + dir) / 2);
	pivo = contribuidores[meio].idade;
	
	while(dir > esq){
		while(contribuidores[esq].idade < pivo){
			esq = esq + 1;
		}
		while(contribuidores[dir].idade > pivo){
			dir = dir - 1;
		}
		if(esq <= dir){
			//realizando as trocas
			aux = contribuidores[esq];
			contribuidores[esq] = contribuidores[dir];
			contribuidores[dir] = aux;
			//faz os limites laterais caminharem para o centro
			esq = esq + 1;
			dir = dir - 1;
		}
	}
	//recursão para continuar ordenando
	if(inicio < dir){
		quick_sort(contribuidores,inicio,dir);
	}if(esq < fim){
		quick_sort(contribuidores,esq,fim);
	}
}
int main(){
	pessoa contribuidores[TAM]={
		{"Bernado",18,66},
		{"Carlos",22,88},
		{"Lucas",20,89},
		{"Mario",91,98},
		{"Maria",30,80},
		{"Roberto",35,81},
		{"Paulo",78,78},
		{"Daniel",54,68},
		{"Simao",61,58},
		{"jack",55,78},
	};
quick_sort(contribuidores,0,TAM-1);
printf("Ordem Crescente de funcionarios por idade: \n\n");

for(int i = 0; i < TAM; i++){
	printf("Nome: %s, 	idade: %d\n", contribuidores[i].nome, contribuidores[i].idade);
}

return 0;
}


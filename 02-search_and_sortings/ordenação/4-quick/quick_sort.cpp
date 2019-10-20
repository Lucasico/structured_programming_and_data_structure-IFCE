#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define TAM 8
int qtdtrocas = 0;
void quick_sort(int vetor[TAM],int inicio,int fim){
	int pivo,esq,dir,meio,aux;
	qtdtrocas++;
	//limites da esquerda e da direita
	esq = inicio;
	dir = fim;
	//ajustando auxiliares do centro
	meio = (int)((esq + dir) / 2);//utilizada só para deixa o pivo centralizado
	pivo = vetor[meio];
	
	while(dir > esq){
		while(vetor[esq] < pivo){
			esq = esq + 1;
		}
		while(vetor[dir] > pivo){
			dir = dir - 1;//qtdtrocas++;
		}
		if(esq <= dir){
			//realizando as trocas
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
			//faz os limites laterais caminharem para o centro
			esq = esq + 1;
			dir = dir - 1;	
		}
	}
	//recursão para continuar ordenando
	if(inicio < dir){
		quick_sort(vetor,inicio,dir);
	}if(esq < fim){
		quick_sort(vetor,esq,fim);	
	} 

}
int main(){
int vetor[TAM] = {10,8,3,15,2,6,4,12};
quick_sort(vetor,0,TAM-1);
for(int i = 0; i < TAM; i++){
	printf(" %d ",vetor[i]);
}
printf("\nQuantidade de trocas : %d\n",qtdtrocas);
return 0;
}


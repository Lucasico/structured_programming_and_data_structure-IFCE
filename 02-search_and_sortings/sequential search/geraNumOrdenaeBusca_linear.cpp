
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#include <time.h>
#define tamVet 100
int funcBusca(int vetor[],int elemento){
	int aux;
	for(int i = 0; i < tamVet; i++){
		for(int j = 0; j < tamVet-1;j++){
			if(vetor[j] > vetor[j + 1]){
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
	for(int i = 0; i < tamVet; i++){
		printf(" %d \n",vetor[i]);
	}
	for(int i = 0; i < tamVet;i++){
		if(elemento == vetor[i]){
			printf("achou: %d \n",i);
		//	return i;
		}else{
			if(elemento < vetor[i]){
				return -1;
			}
		}
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int vet[tamVet],elemento = 2;
    srand((unsigned)time(NULL));
    for(int i = 0; i < tamVet; i++){
    	vet[i] = rand() % tamVet;	
	}
	funcBusca(vet,elemento);
	system("pause");//pausa sistema após execução
	return 0;
}



/*
Escreva um programa que leia uma sequência
com N números inteiros e imprime a sequência
eliminando os elementos repetidos.
– Sequência não-ordenada
– Sequência ordenada
*/
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
void busca(int *vet,int tam){
	for(int i = 0; i < tam; i++){
		for(int j = i+1 ;j < tam;j++){
			if(vet[i] == vet[j]){
				for(int l = j + 1; l < tam;l++){
					vet[l-1] = vet[l];	
				}	
				tam--;
			}
		}
	}
	printf("Vetor sem repetições: ");
	for(int i = 0; i < tam; i++){
		printf(" %d ",vet[i]);
	}
	printf("\n");
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
   	int vet[] = {1,1,7,2,3,6,2,5},tam = 8;
   	
   	busca(vet,tam);

	system("pause");//pausa sistema após execução
	return 0;
}



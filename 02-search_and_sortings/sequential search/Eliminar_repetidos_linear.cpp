/*
Escreva um programa que leia uma sequ�ncia
com N n�meros inteiros e imprime a sequ�ncia
eliminando os elementos repetidos.
� Sequ�ncia n�o-ordenada
� Sequ�ncia ordenada
*/
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
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
	printf("Vetor sem repeti��es: ");
	for(int i = 0; i < tam; i++){
		printf(" %d ",vet[i]);
	}
	printf("\n");
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
   	int vet[] = {1,1,7,2,3,6,2,5},tam = 8;
   	
   	busca(vet,tam);

	system("pause");//pausa sistema ap�s execu��o
	return 0;
}



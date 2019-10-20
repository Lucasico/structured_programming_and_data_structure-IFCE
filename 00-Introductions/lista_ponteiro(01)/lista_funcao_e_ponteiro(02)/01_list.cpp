/*
 Escreva uma função para procurar o maior e o menor valor de um vetor de inteiros. 
 Não retorne e nem imprima os valores.
 Use variáveis inteiras para guardá-los usando a passagem de parâmetro por referência.
*/
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

void extremos(int vetor[],int *maior,int *menor,int control){
	for(int i = 0; i < control; i++){
		if(i == 1){
			*maior = vetor[i];
			*menor = vetor[i];
		}else{
			if(vetor[i] > *maior)
				*maior = vetor[i];
			if(vetor[i] < *menor)
				*menor = vetor[i];
		}
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    
	int vetor[] = {1,2,5,4,6,3,-10,100,0,85},maior,menor;
	
	extremos(vetor,&maior,&menor,10);
	
		printf("O maior valor do vetor: %d\n",maior);
		printf("O menor valor do vetor: %d\n\n",menor);
		
	system("pause");//pausa sistema após execução
	return 0;
}


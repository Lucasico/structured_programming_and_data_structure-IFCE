/*
 Escreva uma fun��o para procurar o maior e o menor valor de um vetor de inteiros. 
 N�o retorne e nem imprima os valores.
 Use vari�veis inteiras para guard�-los usando a passagem de par�metro por refer�ncia.
*/
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

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
		
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}


/*
Escreva um algoritmo que leia dois valores inteiros e chame uma
função que receba estes 2 valores de entrada e retorne o maior
valor na primeira variável e o menor valor na segunda variável.
*/

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
				//num1			//num2
void retorne(int *primeira,int *segunda){
	int maior, menor;
	if(*primeira > *segunda){
		*primeira = *primeira;
		*segunda = *segunda;
	}else{
		maior = *segunda; menor = *primeira;
		*segunda = menor;
		*primeira = maior;
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int num1 = 10,num2 =20;
    printf("primeiro: %d e segundo: %d\n\n",num1,num2);
    retorne(&num1,&num2);
    
    printf("Sempre me retorna o maior na primeira posição\n");
    printf("primeiro: %d e segundo: %d\n\n\n",num1,num2);

	system("pause");//pausa sistema após execução
	return 0;
}

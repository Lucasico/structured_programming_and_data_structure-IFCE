/*
Escreva um algoritmo que leia dois valores inteiros e chame uma
fun��o que receba estes 2 valores de entrada e retorne o maior
valor na primeira vari�vel e o menor valor na segunda vari�vel.
*/

#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
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
    
    printf("Sempre me retorna o maior na primeira posi��o\n");
    printf("primeiro: %d e segundo: %d\n\n\n",num1,num2);

	system("pause");//pausa sistema ap�s execu��o
	return 0;
}

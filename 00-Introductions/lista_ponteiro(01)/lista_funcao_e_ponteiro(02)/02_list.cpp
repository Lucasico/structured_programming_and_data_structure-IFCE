/*
Faça uma função que recebe uma string como parâmetro e converta os caracteres para maiúsculo.
Você pode usar a função int toupper (int ch) da bibleoteca ctype.h para fazer a conversão
*/

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#include<ctype.h>//conversão de caracteres

void convertCaracter(char name){
	name = toupper( name);
	printf("Caracter maiusculo: %c\n\n",name);
}

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	char nome = 'l';
	
	printf("Caracter minusculo: %c\n",nome);
	convertCaracter(nome);
	
	system("pause");//pausa sistema após execução
	return 0;
}


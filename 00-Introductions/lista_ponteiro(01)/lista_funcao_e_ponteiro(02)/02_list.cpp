/*
Fa�a uma fun��o que recebe uma string como par�metro e converta os caracteres para mai�sculo.
Voc� pode usar a fun��o int toupper (int ch) da bibleoteca ctype.h para fazer a convers�o
*/

#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
#include<ctype.h>//convers�o de caracteres

void convertCaracter(char name){
	name = toupper( name);
	printf("Caracter maiusculo: %c\n\n",name);
}

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	char nome = 'l';
	
	printf("Caracter minusculo: %c\n",nome);
	convertCaracter(nome);
	
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}



#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias

	int a = 25;
	int *ptra = &a;
	int b =  *ptra + a;

	printf("%d %p %p %d %d %p \n", a, ptra,&a,*ptra,b,&b);
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}

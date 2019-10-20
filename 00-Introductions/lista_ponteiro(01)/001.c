
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias

	int a = 25;
	int *ptra = &a;
	int b =  *ptra + a;

	printf("%d %p %p %d %d %p \n", a, ptra,&a,*ptra,b,&b);
	system("pause");//pausa sistema após execução
	return 0;
}


#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

int soma(int n){
	if(n == 1)
		return 1;
	else
		return n + soma(n - 1);
}

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int n,mostra;
    
    printf("Digite o numero: ");
    scanf("%d",&n);
    printf("Valor da soma: %d\n\n",soma(n));

	
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}


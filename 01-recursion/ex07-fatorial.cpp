
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

int fatorial(int num);

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int num,exibir;
    
    printf("Digite o numero: ");
    	scanf("%d",&num);
	
	exibir = fatorial(num);
	if(num >= 0){
			printf("\nO fatorial de %d �: %d\n",num,exibir);
	}
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}

int fatorial(int num){
	
	if(num < 0){
		printf("\nERRO fatorial de numero menor que zero\n\n");
	}else{
		if(num == 0 || num == 1)
			return 1;
		else
			return num * fatorial(num - 1);
	}
}


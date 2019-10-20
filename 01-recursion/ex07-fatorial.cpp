
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int fatorial(int num);

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int num,exibir;
    
    printf("Digite o numero: ");
    	scanf("%d",&num);
	
	exibir = fatorial(num);
	if(num >= 0){
			printf("\nO fatorial de %d é: %d\n",num,exibir);
	}
	system("pause");//pausa sistema após execução
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


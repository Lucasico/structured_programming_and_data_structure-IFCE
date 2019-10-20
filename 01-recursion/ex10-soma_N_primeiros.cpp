
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

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

	
	system("pause");//pausa sistema após execução
	return 0;
}


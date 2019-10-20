/*
	função recursiva que calcula o 
*/
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int tamString(char nome[]);

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    char name[25];
    int num;
    
    printf("Digite o nome: ");
    	fgets(name,sizeof(name),stdin);
    	
    printf("O tamanho da string é: %d\n\n",tamString(name));
    
	system("pause");//pausa sistema após execução
	return 0;
}
int tamString(char nome[]){
	
	if(nome[0] == '\n')
	
		return 0;
	else	
		return 1 + tamString(&nome[1]);
}

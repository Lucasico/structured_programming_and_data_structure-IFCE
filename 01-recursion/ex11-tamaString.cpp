/*
	fun��o recursiva que calcula o 
*/
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

int tamString(char nome[]);

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    char name[25];
    int num;
    
    printf("Digite o nome: ");
    	fgets(name,sizeof(name),stdin);
    	
    printf("O tamanho da string �: %d\n\n",tamString(name));
    
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}
int tamString(char nome[]){
	
	if(nome[0] == '\n')
	
		return 0;
	else	
		return 1 + tamString(&nome[1]);
}

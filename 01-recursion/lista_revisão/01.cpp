
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

int inverte(int vet[],int tamanho)
{
	if(tamanho == 0){
		printf(" %d ",vet[tamanho]);
		return vet[0];
	}
	else{
		printf(" %d ",vet[tamanho]);
	//	tamanho = tamanho - 1;
		return inverte(vet, tamanho - 1);	
	}
		
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
   int vet[] = {1,2,3,4},tam = 3;
   
   inverte (vet,tam);
   
	return 0;
}


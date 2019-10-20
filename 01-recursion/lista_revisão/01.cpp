
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

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


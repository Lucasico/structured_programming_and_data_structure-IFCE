#include <stdio.h>
#define TAM  5
/*
 Dado um número e um array 
 ordenado,escreva um algoritmode insertionsort para inserir
 esse valor na sua posição correta. Desloque os outros números e se 
 necessário. 
*/
int main(){
	int vetor[TAM] = {1,3,4,5};
	int i,j,aux;
	printf("Digite um numero: ");
	scanf("%d",&vetor[4]);
	
	for(i = 1; i < TAM; i++){
		aux = vetor[i];
		j = i - 1;
		
		while(j >= 0 && vetor[j] > aux){
			vetor[j + 1] = vetor[j];
			j = j - 1;		
		}
		vetor[j + 1] = aux;	
	}
	//ordenação por inserção baralho
	for(i = 0;i < TAM; i++)	{
		printf(" %d ",vetor[i]);
	}
	
	return 0;
}


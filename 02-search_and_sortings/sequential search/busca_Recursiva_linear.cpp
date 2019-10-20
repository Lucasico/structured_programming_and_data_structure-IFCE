
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
int busca_R(int vet[],int tam,int element){
	
	if(tam == 0){
		return -1;
	}else{
		
		if(element == vet[tam - 1]){
			printf(" %d ",tam);
			// return tam-1; --> caso queira imprimir apenas um indice, senão descomenta.
		}
		
	}
	printf("\nChegou: ");
	return busca_R(vet,tam-1,element);

}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int vet[10] = {11,10,1,3,2,0,3,5,2,7},tam = 10,element = 2;
    
    busca_R(vet,tam,element);

	system("pause");//pausa sistema após execução
	return 0;
}



#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define tamVet 100000
int busca_binaria(int *vet, int element){
	int inicio = 0,meio,fim = tamVet - 1;
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		if(element < vet[meio])
			fim = meio - 1;
		else if(element > vet[meio])
			inicio = meio + 1;
		else
			return meio;
	}
	return -1;
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int vet[tamVet],elem = 51441;
    
    for(int i = 0; i < tamVet;i++){
    	vet[i] = i;
	}
	for(int i = 0; i < tamVet;i++){
    	printf(" %d ",vet[i]);
	}
	printf("\n%d\n",busca_binaria(vet,elem));
  //  int exibir = busca_binaria(vet,elem,tam);   
 //	printf("%d\n",exibir);
	system("pause");//pausa sistema após execução
	return 0;
}




#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
int buscaBinReq(int *vet,int tam,int menor,int maior,int element){

	while(maior >= menor){
		int meio=(maior + menor) / 2;
		if(element > vet[meio]){
			return buscaBinReq(vet,tam,meio+1,maior,element);
		}
		else if(element < vet[meio]){
			return buscaBinReq(vet,tam,menor,maior-1,element);
		}
		else
			return meio;
	}
	return -1;
	
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int vet[]={5,6,7,9,10,12,16,18,20},tam = sizeof(vet) / sizeof(int);
	int element = 23,menor = 0,maior = tam - 1;
	
	printf(" Elemento na posi.: %d \n",buscaBinReq(vet,tam,menor,maior,element));
	
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}



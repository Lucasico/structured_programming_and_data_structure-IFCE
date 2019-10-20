
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int somaVet(int vet[],int tam){
 int soma = 0;
	 if(tam == 0){
	 	 soma = vet[0];
		 return soma;	
	 }	
	 else{
	 	return soma = vet[tam] + somaVet(vet,tam-1);
		 printf("%d", somaVet(tam)) 	
	 }
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
   int vet[] = {20,11,10,40}, tam = 3, mostra;
   
   mostra = somaVet (vet,tam);
   printf("%d", mostra);
   
	return 0;
}


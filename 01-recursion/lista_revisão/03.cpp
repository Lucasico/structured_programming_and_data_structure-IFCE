
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int numMaior (int n, int v[])
{ 
int maior;
   if (n == 0){
   	
   	 	return v[0];
   }
   else
   {
      maior = numMaior (n-1, v);
      
      if (maior > v[n]){
        	return maior;	 
	  }	
   }
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
   int vet[] = {101,700,100,40},tam = 4,mostra;
   
   mostra = numMaior (tam,vet);
   printf("%d",mostra);
   
	return 0;
}


/*
Escreva uma fun��o para calcular a m�dia de n�meros armazenados em um vetor. 
Fa�a outra fun��o que mostra os n�meros que est�o abaixo da m�dia e acima da m�dia.
*/

#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

#define totNumeros 6;
float calcmedia(float numeros[],float *media,int control){
	float soma = 0.0;
	for(int i = 0; i < control; i++)
		soma = soma + numeros[i];
	
	*media = soma / totNumeros;
	
	return *media;
}
void exibirMenorqueMedia(float numeros[],float *parametro,int controle){
	
	printf("N�meros menores que %.2f: ",*parametro);
	for(int i = 0;i < controle;i++){
		if(numeros[i] < *parametro)
			printf("%.1f ",numeros[i]);
	}
	printf("\nN�meros maiores que %.2f: ",*parametro);
	for(int i = 0;i < controle;i++){
		if(numeros[i] > *parametro)
			printf("%.1f ",numeros[i]);
	}
	
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int i;
    float numeros[]={6.0,7.5,5.9,8.5,3,10},media;
  
   printf("Calcula media dos elementos do vetor\ne exibe os valores menores que a media\n\n");
   printf("A media dos elementos do vetor: %.2f\n",calcmedia(numeros,&media,6));

   exibirMenorqueMedia(numeros,&media,6);
   printf("\n\n\n");
	
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}


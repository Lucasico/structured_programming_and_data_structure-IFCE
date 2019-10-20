/*
Escreva uma função para calcular a média de números armazenados em um vetor. 
Faça outra função que mostra os números que estão abaixo da média e acima da média.
*/

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

#define totNumeros 6;
float calcmedia(float numeros[],float *media,int control){
	float soma = 0.0;
	for(int i = 0; i < control; i++)
		soma = soma + numeros[i];
	
	*media = soma / totNumeros;
	
	return *media;
}
void exibirMenorqueMedia(float numeros[],float *parametro,int controle){
	
	printf("Números menores que %.2f: ",*parametro);
	for(int i = 0;i < controle;i++){
		if(numeros[i] < *parametro)
			printf("%.1f ",numeros[i]);
	}
	printf("\nNúmeros maiores que %.2f: ",*parametro);
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
	
	system("pause");//pausa sistema após execução
	return 0;
}


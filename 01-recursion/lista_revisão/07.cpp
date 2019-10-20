/*
Escreva uma função para separar a parte inteira e a parte
fracionária de um número real, seguindo o protótipo:
void divide(float num, int *inteira, float *frac);
*/
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
void divide(float num, float *inteira, float *frac){
	*inteira =  (int)num;
	float resto;
	*frac = num - *inteira;
	
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	
    float num = 3.1415,inteiro = 0.0,resto = 0.0;
    
    divide(num,&inteiro,&resto);
   	printf("Número real: %.4f\n",num);
	printf("Parte inteira: %.2f\n",inteiro);
	printf("Parte fracionária: %.4f\n\n",resto);   	
	system("pause");//pausa sistema após execução
	return 0;
}



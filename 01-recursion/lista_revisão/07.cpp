/*
Escreva uma fun��o para separar a parte inteira e a parte
fracion�ria de um n�mero real, seguindo o prot�tipo:
void divide(float num, int *inteira, float *frac);
*/
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
void divide(float num, float *inteira, float *frac){
	*inteira =  (int)num;
	float resto;
	*frac = num - *inteira;
	
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	
    float num = 3.1415,inteiro = 0.0,resto = 0.0;
    
    divide(num,&inteiro,&resto);
   	printf("N�mero real: %.4f\n",num);
	printf("Parte inteira: %.2f\n",inteiro);
	printf("Parte fracion�ria: %.4f\n\n",resto);   	
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}



#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
/*
Crie um programa para calcular a �rea e o per�metro de um ret�ngulo.
void calculaAreaRetangulo(float base, float altura, floar *area, float *perimetro);
*/
void calculaAreaRetangulo(float base, float altura, float *area, float *perimetro);
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias

    float base,altura,area,perimetro;

    printf("Digite a base do ret�ngulo: ");
        scanf("%f",&base);

    printf("Digite a altura do ret�ngulo: ");
        scanf("%f",&altura);

    calculaAreaRetangulo(base,altura,&area,&perimetro);

    printf("\nArea do retangulo: %.3f\n",area);
    printf("Perimetro do retangulo: %.3f\n\n",perimetro);

	system("pause");//pausa sistema ap�s execu��o
	return 0;
}
void calculaAreaRetangulo(float base, float altura, float *area, float *perimetro){
    *area = base  * altura;
    *perimetro = base * 2 + altura * 2;
}

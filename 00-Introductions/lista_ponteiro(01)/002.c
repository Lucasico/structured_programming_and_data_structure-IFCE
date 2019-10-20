#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
/*
Crie um programa para calcular a área e o perímetro de um retângulo.
void calculaAreaRetangulo(float base, float altura, floar *area, float *perimetro);
*/
void calculaAreaRetangulo(float base, float altura, float *area, float *perimetro);
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias

    float base,altura,area,perimetro;

    printf("Digite a base do retângulo: ");
        scanf("%f",&base);

    printf("Digite a altura do retângulo: ");
        scanf("%f",&altura);

    calculaAreaRetangulo(base,altura,&area,&perimetro);

    printf("\nArea do retangulo: %.3f\n",area);
    printf("Perimetro do retangulo: %.3f\n\n",perimetro);

	system("pause");//pausa sistema após execução
	return 0;
}
void calculaAreaRetangulo(float base, float altura, float *area, float *perimetro){
    *area = base  * altura;
    *perimetro = base * 2 + altura * 2;
}

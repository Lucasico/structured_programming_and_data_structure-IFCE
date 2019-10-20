
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int mdc(int a,int b){
int result = a % b;
    if(result == 0){

        return b;
    }
    else
    {
        return mdc(b , result);
    }
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias

	int a,b,exibir;

	printf("Digite o primeiro valor: ");
        scanf("%d",&a);
    printf("\nDigite o segundo valor: ");
        scanf("%d",&b);

        exibir = mdc(a,b);

        printf("\n\nO MDC de %d e %d é : %d\n",a,b,exibir);

	system("pause");//pausa sistema após execução
	return 0;
}

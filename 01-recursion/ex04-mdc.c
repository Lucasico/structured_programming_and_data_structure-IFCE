
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

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

        printf("\n\nO MDC de %d e %d � : %d\n",a,b,exibir);

	system("pause");//pausa sistema ap�s execu��o
	return 0;
}

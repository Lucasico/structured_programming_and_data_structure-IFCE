/*
Calcule uma função recursiva que receba 2
números (x e n) e calcule xn
– Caso base: x0 = 1
– Caso geral: xn = x * xn-1

*/

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

int potencia(int base,int exp){
    if(exp == 0.0){
        return base = 1.0;
    }else{
        return (potencia(base,exp - 1.0) * base);
    }

}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    // zerando o buffer %*c: scanf("%s%*c",&vet);
    int base,expo,exibir;

    printf ("Digite a base: ");
        scanf("%d",&base);
    printf("Digite o expoente: ");
        scanf("%d",&expo);

    exibir = potencia(base,expo);

    printf("%d elevado a %d = %d\n",base,expo,exibir);

	system("pause");//pausa sistema após execução
	return 0;
}

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
int fibo(int n){
    if( n == 0 || n == 1){
        return n;
    }else{

        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias

	int n,exibir;
	printf("Digi: ");
	scanf("%d",&n);

	exibir = fibo(n);
	printf("%d\n",exibir);


	system("pause");//pausa sistema após execução
	return 0;
}

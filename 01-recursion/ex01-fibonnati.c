#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
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


	system("pause");//pausa sistema ap�s execu��o
	return 0;
}

#include<stdio.h>
#include<locale.h>
//fibonatti
int main(){
	setlocale(LC_ALL,"portuguese");
	int num1,num2,qtd,soma;
	num1 = 1;
	num2 = 0;
	
	printf("Digite a quantidade de digitos da sequencia: ");
		scanf("%d",&qtd);
		
	for(int i = 0; i < qtd; i++){
		printf(" %d ",soma);
		
		soma = num1 + num2;
		num1 = num2;
		num2 = soma;
		
		
	}
	
	return 0;
	
}

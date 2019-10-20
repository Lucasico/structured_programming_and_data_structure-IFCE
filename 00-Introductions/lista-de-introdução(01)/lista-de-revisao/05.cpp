#include<stdio.h>
#include<locale.h>


int functionSoma(int num1,int num2){
	int soma;
	soma = num1 + num2;
	return soma;
}
int main(){
	setlocale(LC_ALL,"portuguese");
	int num1,num2,exibir;
	
	printf("Digite o primeiro número: ");
		scanf("%d",&num1);
	printf("Digite o segundo número: ");
		scanf("%d",&num2);
		
	exibir = functionSoma(num1, num2);
	
	printf("\nA soma de %d + %d = %d",num1,num2,exibir);
	
	return 0;
}



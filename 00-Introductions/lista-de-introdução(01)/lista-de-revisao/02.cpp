#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	int numero;
	
	printf("Digite um número: ");
		scanf("%d",&numero);
		
		if(numero % 2 == 0){
			printf("Número Par");
		}else{
			printf("Número primo");
		}
	return 0;
}

#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	int numero;
	
	printf("Digite um n�mero: ");
		scanf("%d",&numero);
		
		if(numero % 2 == 0){
			printf("N�mero Par");
		}else{
			printf("N�mero primo");
		}
	return 0;
}

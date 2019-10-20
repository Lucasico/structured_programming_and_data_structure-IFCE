#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char nome[50];
	int idade;
	
	printf("Digite nome: ");
		scanf("%s",&nome);
	
	printf("digite a idade: ");
		scanf("%d",&idade);
		
		if(idade >= 18){
			printf("%s tem %d de idade, portanto é maior de idade",nome,idade);
		}else{
			printf("%s tem %d de idade, portanto é menor de idade",nome,idade);
		}
	return 0;
}

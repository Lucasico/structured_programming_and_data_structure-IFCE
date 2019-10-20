#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	float nota1,nota2,nota3,media;
	
	printf("Digite a primera nota: ");
		scanf("%f",&nota1);
	printf("Digite a segunda nota: ");
		scanf("%f",&nota2);
	printf("Digite a terceira nota: ");
		scanf("%f",&nota3);	
		
		media = (nota1 + nota2 * 2 + nota3 * 3) / 6.0;
		
		printf("\nMedia = %.2f\n",media);
		
		if(media >= 9.0){
			printf("Conceito: A");
		}
		
		if(media >= 7.5 && media < 9.0){
			printf("Conceito: B");
		}
		
		if(media >= 6.0 && media < 7.5){
			printf("Conceito: C");
		}
		
		if(media >= 4.0 && media < 6.0){
			printf("Conceito: D");
		}
		
		if(media < 4.0 ){
			printf("Conceito: E");
		}
		
		
	return 0;
}

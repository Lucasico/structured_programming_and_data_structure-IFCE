
#include<stdio.h>
#include<locale.h>

int somaVetor(int vet[10]){
	int soma,vet2[10];

	for(int i = 0; i <= 8; i++){
		soma = vet[i] + vet[i + 1];
		vet2[i] = soma;
	}
	for(int i = 0; i <= 8; i++){
        printf(" %d ",vet2[i]);
	}
}
int main(){
	setlocale(LC_ALL,"portuguese");
	int vet[10];

	for(int i = 0; i < 10; i++){
		printf("Digite um valor para %d do vetor: ",i);
			scanf("%d",&vet[i]);
	}
	printf("\n");
	
	somaVetor(vet);


	return 0;
}

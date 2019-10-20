#include<stdio.h>
#include<locale.h>
#include<string.h>

void functionExibir(struct dados alunos[],int tamanho,int totNotas);

struct dados{
		int matricula;
		char nome[50];
		float notas[3];
};

struct dados alunos[5];

int main(){
	setlocale(LC_ALL,"portuguese");
	
	for(int i = 0; i < 5 ; i++){
		printf("Digite a matricula: ");
			scanf("%d",&alunos[i].matricula);
		printf("Digite o nome: ");
			scanf("%s*c",&alunos[i].nome);
			for(int j = 0; j < 3; j ++){
				printf("Digite a %d nota: ",j+1);
					scanf("%f",&alunos[i].notas[j]);		
			}
		printf("\n----------------------------------\n");
	}
	functionExibir(alunos,5,3);
	
	return 0;
}
void functionExibir(struct dados alunos[],int tamanho,int totNotas){
	float media = 0.0;
	for(int i = 0;i < tamanho;i++){
		printf("Matricula: %d\n",alunos[i].matricula);
		printf("Nome: %s",alunos[i].nome);
		
		for(int j = 0; j < totNotas;j++)
			media = (alunos[i].notas[j] + media);	
		
		media = media / totNotas;
		
			printf("\nMedia do %d aluno: %.2f",i,media);
			printf("\n---------------------------------------\n");
		
		media = 0.0;
	}
}

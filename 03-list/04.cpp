#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define TAM 4
//struct aluno
typedef struct aluno{
	int matricula;
	char nome[10];
	float media;
}aluno;

aluno turma[TAM];

void ordenaAlunos(aluno *turma){
	int i,j;
	aluno aux;
	for(i=0;i<TAM;i++){
		for(j=0;j<TAM-1-i;j++){
			if(turma[j].media > turma[j+1].media ){
				aux = turma[j];
				turma[j] = turma[j+1]; //comparações
				turma[j+1] = aux;	
			}else{
				if(turma[j].media == turma[j+1].media){
					if(strcmp(turma[j].nome, turma[j+1].nome) > 0){
						aux = turma[j];
						turma[j] = turma[j+1]; //comparações
						turma[j+1] = aux;
					}
				}
			}
		}
	}
}
void func_exibir(aluno *turma){
	int i;
	for(i = 0; i < TAM; i++){
		printf("Matricula: %d, nome: %s, media: %.2f\n",turma[i].matricula,turma[i].nome,turma[i].media);
	}
}
int main(){
	int i,j;
	aluno aux;
	aluno turma[TAM]={
		{123,"Lucas",8.1},
		{456,"Carlos",8.5},
		{321,"Antoria",8.5},
		{317,"joao",8.4},
	};
	ordenaAlunos(turma);
	func_exibir(turma);	
return 0;
}


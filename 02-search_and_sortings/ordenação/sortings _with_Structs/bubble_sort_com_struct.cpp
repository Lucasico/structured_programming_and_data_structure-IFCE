#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define tam 5
typedef struct alunos{
	char nome[25];
	int matricula;
}alunos;

alunos turma[5];

alunos ordenaStruct(alunos *turmaBusca);
int buscaStruct(alunos *turmaBusca,int busca);

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int buscaMatricula, resultado;
	
    alunos turma[tam] = {
		{"Lucas Santos",123},
		{"Marco Andre",321},
		{"Anderso mota",100},
		{"Paulo Cesar",85},
		{"Maria Silva",327},
	};
	ordenaStruct(turma);
	printf("\nDigite a Matricula do aluno que deseja busca: ");
	scanf("%d",&buscaMatricula);
	resultado = buscaStruct(turma,buscaMatricula);
	if(resultado != -1){
		printf("\n---- Dados do aluno pesquisado ---\n");
		printf("Aluno: %s\n",turma[resultado].nome);
		printf("Matricula: %d",turma[resultado].matricula);
		printf("\n-----------------------------------\n");
	}else{
		printf("Matricula não encontrada\n");
	}
	system("pause");//pausa sistema após execução
	return 0;
}
alunos ordenaStruct(alunos *turmaBusca){
	for(int i = 0; i < tam; i++){
		for(int j = i + 1; j < tam; j++){
			if(turmaBusca[i].matricula > turmaBusca[j].matricula){
				alunos aux = turmaBusca[i];
				turmaBusca[i] = turmaBusca[j];
				turmaBusca[j] = aux;	
			}
		}	
	}	
}
int buscaStruct(alunos *turmaBusca,int busca){
int inicio = 0, meio , fim = tam - 1;
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		if(busca < turmaBusca[meio].matricula){
			fim = meio - 1;
		}	
		else if(busca > turmaBusca[meio].matricula){
			inicio = meio + 1;
		}	
		else{
			return meio;
		}
	}return -1;
}

#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
#define tam 5
typedef struct alunos{
	char nome[25];
	int matricula;
}alunos;
alunos turma[5];

alunos ordenaStruct(alunos *turmaBusca);

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
	for(int i = 0; i < tam;i++){
		printf("%s\n",turma[i].nome);
	}
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}
alunos ordenaStruct(alunos *turmaBusca){
	for(int i = 0; i < tam;i++){
		int menor = i;
		for(int j = i + 1; j < tam; j++){
			if(strcmp(turmaBusca[j].nome, turmaBusca[menor].nome) < 0){
				menor = j;
			}
		}
		alunos aux = turmaBusca[menor];
		turmaBusca[menor] = turmaBusca[i];
		turmaBusca[i] = aux;
	}
}

/*
	realizar busca linear em Struct, por matricula.
*/
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
typedef struct aluno{
	int matricula;
	char nome[30];
	float n1,n2,n3;
}aluno; aluno turma[4];

int buscaSequencialMatricula(aluno *turma, int n, int matricula){
	for(int i = 0; i < n; i++){
		if(matricula == turma[i].matricula){
			return i;
		}
	}
	return -1;
}

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int n = 4, matricula = 2;
   aluno turma[4] = {
   		{1,"jo�o",9.5,10,8.5},
   		{2,"Paulo",9.5,10,8.5},
   		{3,"Mario",9.5,10,8.5},
   		{4,"Marianna",9.5,10,8.5},
	};
	 buscaSequencialMatricula(turma,n,matricula);

	system("pause");//pausa sistema ap�s execu��o
	return 0;
}



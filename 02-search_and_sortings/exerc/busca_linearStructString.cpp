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

void buscaSequencialNome(aluno *turma, int n, char *name){
	for(int i = 0; i < n; i++){
		if(strcmp(name,turma[i].nome) == 0){
			printf("Nomes iguais na posi��o: %d\n",i);
		}else{
			printf("\nNomes diferentes nas posi��es: %d\n",i);
		}
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int n = 4;
	char name[] = "Lucas";
   aluno turma[4] = {
   		{1,"jo�o",9.5,10,8.5},
   		{2,"Lucas",9.5,10,8.5},
   		{3,"Mario",9.5,10,8.5},
   		{4,"Lucas",9.5,10,8.5},
	};
buscaSequencialNome(turma,n,name);

	system("pause");//pausa sistema ap�s execu��o
	return 0;
}




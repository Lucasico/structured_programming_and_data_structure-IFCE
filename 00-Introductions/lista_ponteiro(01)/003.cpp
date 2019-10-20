/*
Crie uma estrutura para guardar as informa��es de um aluno. O aluno deve ter um c�digo
(int), nome (at� 30 caracteres) e uma lista de disciplinas. Cada disciplina possui um c�digo
(int), nome( at� 20 caracteres), 3 notas (float), carga hor�ria (int), quantidade de faltas (int),
m�dia (float) e situa��o (at� 20 caracteres).
Crie uma fun��o para calcular a m�dia aritm�tica do aluno
void media (float n1, float n2, float n3, float *media)
Crie uma fun��o para preencher a situa��o do aluno de acordo com as regras abaixo:
*/

#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
#define Tamvet 2

typedef struct listDisc{
	int codDisc,cargHrDisc,qtdFaltaDisc;
	char nameDisc[20],situaDisc[25];
	float media,n1,n2,n3;
	
}lista;

struct aluno{
	int codAluno;
	char nameAluno[30];
	lista disc[2];
};

//	calcMedia(dados.disc[i].n1,dados.disc[i].n2,dados.disc[i].n3,&dados.disc[i].media);
void calcMedia(float nota1,float nota2,float nota3,float *media){
	*media = (nota1 + nota2 + nota3) / 3.0;
	printf("\nA m�dia nesta disciplina foi: %.2f",*media);	
}

//calcSituacao(&dados.disc[i].media,dados.disc[i].cargHrDisc,dados.disc[i].qtdFaltaDisc,dados.disc[i].situaDisc);
void calcSituacao(float *mediaSituacao,int cargHrDisc,int qtdFaltaDisc, char situaDisc[]){
	int porcTolFalt;
	porcTolFalt = (cargHrDisc * 25) / 100;
	
	if(qtdFaltaDisc <= porcTolFalt){
		if(*mediaSituacao >= 7.0){
			strcpy(situaDisc,"Aprovado");
			printf("\nSitua��o: %s",situaDisc);	
			
		}else{
			strcpy(situaDisc,"Reprovado por m�dia");
			printf("\nSitua��o: %s",situaDisc);	
			
		}
	}else{
		strcpy(situaDisc,"Reprovado por falta");
		printf("\nSitua��o: %s",situaDisc);	
		
	}
		
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	struct aluno dados;
	float mostraMedia;
   	printf("\n---Sistema de dados de aluno---\n\n");

	//preenchimento automatico, para evitar a fadiga.   
	strcpy(dados.nameAluno,"Lucas Bezerra dos santos");
	printf("Nome do Aluno: %s",dados.nameAluno);
	dados.codAluno = 123;
	printf("\nC�digo do aluno: %d",dados.codAluno);
	
	for(int i = 0; i < Tamvet; i++){
		//preenchimento automatico, para evitar a fadiga.   
		dados.disc[i].codDisc = i;
		strcpy(dados.disc[i].nameDisc,"Estrutura de Dados");
		printf("\nDisc�plina: %s, com cod�go: %d",dados.disc[i].nameDisc,dados.disc[i].codDisc);
		
		printf("\nDigite a carga hor�ria da disciplina: ");
		scanf("%d",&dados.disc[i].cargHrDisc);
		
		printf("\nDigite a quantidade de faltas do aluno: ");
		scanf("%d",&dados.disc[i].qtdFaltaDisc);
		
		printf("\nDigite a primeira nota: ");
		scanf("%f",&dados.disc[i].n1);
		
		printf("\nDigite a segunda nota: ");
		scanf("%f",&dados.disc[i].n2);
		
		printf("\nDigite a terceira nota: ");
		scanf("%f",&dados.disc[i].n3);
		
		calcMedia(dados.disc[i].n1,dados.disc[i].n2,dados.disc[i].n3,&dados.disc[i].media);
		calcSituacao(&dados.disc[i].media,dados.disc[i].cargHrDisc,dados.disc[i].qtdFaltaDisc,dados.disc[i].situaDisc);
		
		printf("\n----------------------------------------------\n");
	}
	printf("\n\n");
	system("pause");//pausa sistema ap�s execu��o
	return 0;	
}

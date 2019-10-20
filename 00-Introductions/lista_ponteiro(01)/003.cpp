/*
Crie uma estrutura para guardar as informações de um aluno. O aluno deve ter um código
(int), nome (até 30 caracteres) e uma lista de disciplinas. Cada disciplina possui um código
(int), nome( até 20 caracteres), 3 notas (float), carga horária (int), quantidade de faltas (int),
média (float) e situação (até 20 caracteres).
Crie uma função para calcular a média aritmética do aluno
void media (float n1, float n2, float n3, float *media)
Crie uma função para preencher a situação do aluno de acordo com as regras abaixo:
*/

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
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
	printf("\nA média nesta disciplina foi: %.2f",*media);	
}

//calcSituacao(&dados.disc[i].media,dados.disc[i].cargHrDisc,dados.disc[i].qtdFaltaDisc,dados.disc[i].situaDisc);
void calcSituacao(float *mediaSituacao,int cargHrDisc,int qtdFaltaDisc, char situaDisc[]){
	int porcTolFalt;
	porcTolFalt = (cargHrDisc * 25) / 100;
	
	if(qtdFaltaDisc <= porcTolFalt){
		if(*mediaSituacao >= 7.0){
			strcpy(situaDisc,"Aprovado");
			printf("\nSituação: %s",situaDisc);	
			
		}else{
			strcpy(situaDisc,"Reprovado por média");
			printf("\nSituação: %s",situaDisc);	
			
		}
	}else{
		strcpy(situaDisc,"Reprovado por falta");
		printf("\nSituação: %s",situaDisc);	
		
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
	printf("\nCódigo do aluno: %d",dados.codAluno);
	
	for(int i = 0; i < Tamvet; i++){
		//preenchimento automatico, para evitar a fadiga.   
		dados.disc[i].codDisc = i;
		strcpy(dados.disc[i].nameDisc,"Estrutura de Dados");
		printf("\nDiscíplina: %s, com codígo: %d",dados.disc[i].nameDisc,dados.disc[i].codDisc);
		
		printf("\nDigite a carga horária da disciplina: ");
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
	system("pause");//pausa sistema após execução
	return 0;	
}

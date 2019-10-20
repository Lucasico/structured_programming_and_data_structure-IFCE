/*2) Crie uma estrutura para representar um aluno 
de uma disciplina com os dados a seguir:
• número da matrícula -> array char de 10 posições
• nome do aluno -> array de char de 30 posições
• nota1 -> float
• nota2 -> float
• nota3 -> float

Escreva uma função que ordene em ordem decrescente
 de média um vetor da estrutura declarada.
Considere que a média é calculada de acordo com a 
fórmula (P1+P2+P3)/3 e utilize o insertion sort ou 
selection sort para ordenar.*/
#include <stdio.h>

typedef struct alunos{
	int num_mat[10];
	char nome[30];
	float n1,n2,n3,media;
	
}alunos;
alunos c1[3];

void preenche(int tam,alunos *vet){
	int num = 1,i;
	for(i=0;i<tam;i++){
		printf("Digite a nota do aluno %d: ",num);
		scanf("%f",&c1[i].n1);
		printf("Digite a nota do aluno %d: ",num);
		scanf("%f",&c1[i].n2);
		printf("Digite a nota do aluno %d: ",num);
		scanf("%f",&c1[i].n3);
		num++;
		c1[i].media = (c1[i].n1 + c1[i].n2 + c1[i].n3)/3.0;
	
	}
}
void ordena(int tam,alunos *vet){
	int i,j;
	for(i =0; i < tam; i++){
		int menor = i;
		for(j = i + 1; j < tam; j++){
			if(vet[j].media > vet[menor].media){
				menor = j;
			}
		}
		if(menor != i){
			alunos aux = vet[menor];
			vet[menor] = vet[i];
			vet[i] = aux;
		}	
	}
	printf("\n");
	for(i = 0; i < tam;i++){
		printf("Medias: %.2f ",vet[i].media);
	}
}

int main(){
	int tam = 3;
	preenche(tam,c1);
	ordena(tam,c1);	
	
	return 0;
}

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

typedef struct funcionario{
	char nome[20];
	float valor_hr_trab;
	int hr_trab;
	float salarioMes;
}funcionario;
funcionario equipe[4];
void ordenaSelectionNome(funcionario *equipe, int tam){
	int i, j;
	funcionario aux;
	for(i = 0; i < tam;i++){
		int menor = i;
		for(j = i +1; j < tam; j++){
			if(strcmp(equipe[j].nome , equipe[menor].nome) < 0){
				menor = j;
			}
		}
		if(menor != i){
			aux = equipe[menor];
			equipe[menor] = equipe[i];
			equipe[i] = aux;	
		}
	}
}
int buscaBinaria(funcionario equipe[],int tam, char *nome){
	int inicio = 0, fim= tam - 1;
	
	while(inicio <= fim){
		int meio = (inicio + fim) / 2;
		if(strcmp(nome, equipe[meio].nome) > 0){
			inicio = meio + 1;
		}else if(strcmp(nome, equipe[meio].nome) < 0){
			fim = meio - 1;
		}else{
			return meio;//retorna o endereço de memoria da posição encontrada
		}
	}
	return -1;
}
void calcSalario(funcionario equipe[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		equipe[i].salarioMes = (equipe[i].hr_trab * equipe[i].valor_hr_trab * 30);
	}
}
float calcMediaHoraSal(funcionario equipe[],float mediaHora,int tam){
	int i;
	float somaAux;
	for(i = 0; i < tam; i++){
		somaAux = equipe[i].valor_hr_trab + somaAux;
	}
	mediaHora = (somaAux / 4.0);
	return mediaHora;
}
void ordenaSelectionSalario(funcionario equipe[], int tam){
	int i, j;
	funcionario aux;
	for(i = 0; i < tam;i++){
		int menor = i;
		for(j = i +1; j < tam; j++){
			if(equipe[j].salarioMes > equipe[menor].salarioMes){
				menor = j;
			}
		}
		if(menor != i){
			aux = equipe[menor];
			equipe[menor] = equipe[i];
			equipe[i] = aux;	
		}
	}
}
void exibirMaioresSalarios(funcionario equipe[], int tam){
	printf("--- 3 Maiores salários ---\n");
	printf("----------------------------\n");
	printf("Nome: %s, Salário: %.2f\n",equipe[0].nome,equipe[0].salarioMes);
	printf("Nome: %s,   Salário: %.2f\n",equipe[1].nome,equipe[1].salarioMes);
	printf("Nome: %s,  Salário: %.2f\n",equipe[2].nome,equipe[2].salarioMes);
}
void merge(funcionario equipe[], int indiceEsquerdo,int meio, int indiceDireito){
	int n1 = meio - indiceEsquerdo + 1;//tam do vetor da esquerda
	int n2 = indiceDireito - meio;//tam do vetor da direita
	
	funcionario vetorEsquerdo[n1];
	funcionario vetorDireito[n2];
	
	int i,j,k;
	
	for(i = 0; i < n1; i++){
		vetorEsquerdo[i] = equipe[indiceEsquerdo + i];
	}
	//passa os elementos do vetor principal para o vetor da direita
	for(j = 0; j < n2; j++){
		vetorDireito[j] = equipe[meio + 1 + j];
	}
	//zerando valores das variaveis auxiliares
	i = 0; j = 0; k = indiceEsquerdo;
	while(i < n1 && j < n2){
		/*
			caso o valor na esquerda seja menor
			passo para o vetor principal o valor menor
			incrementa o valores auxiliares
		*/
		if(vetorEsquerdo[i].valor_hr_trab < vetorDireito[j].valor_hr_trab){
			equipe[k] = vetorEsquerdo[i];
			i++;
		}else{
			equipe[k] = vetorDireito[j];
			j++;
		}
		k++;//almenta o indice de posicionamento do vetor principal
	}
	while(i < n1){
		equipe[k] = vetorEsquerdo[i];
		i++;
		k++;
	}
	/*
		se faltarem alguns elementos do vetor do array direito passa eles
		para o array principal.
	*/
	while(j < n2){
		equipe[k] = vetorDireito[j];
		j++;
		k++;
	}
}
void merge_sort(funcionario equipe[],int indiceEsquerdo, int indiceDireito){
	if(indiceEsquerdo < indiceDireito){
		//Encontra o meio do vetor original..
		int meio = indiceEsquerdo +(indiceDireito - indiceEsquerdo) / 2;
		//Da metade para trás do vetor original
		merge_sort(equipe,indiceEsquerdo,meio);
		//da metade para frente do vetor original
		merge_sort(equipe,meio + 1, indiceDireito);
		//chamada da função para unir os sub-vetores criados com a devida ordenação
		merge(equipe,indiceEsquerdo,meio,indiceDireito);
	}
}
void ganha_acima_mediaHr(funcionario equipe[], float mediaHoraSalario, int tam){
	printf("\n----------------------------\n");
	printf("Valor médio da hora trabalhada: %.2f\n",mediaHoraSalario);
	printf("----------------------------\n");
	printf("Ganha em acima da média por hora:\n");
	for(int i = 0; i < tam; i++){
		if(equipe[i].valor_hr_trab > mediaHoraSalario){
			printf("Nome: %s, Valor da hora trabalhada: %.2f\n",equipe[i].nome,equipe[i].valor_hr_trab);
		}
	}
}
int main(){
int opcao,tam = 4;
float mediaHoraSalario;
char nomeBusca[20];
int resposta;
	setlocale(LC_ALL,"portuguese");
printf("	Sistema de gerenciamento de funcionario referente a questão 05\n");
printf("1 - Buscar um funcionario\n");
printf("2 - Exibir os 3 maiores salarios\n");
printf("3 - Mostra aqueles que ganham acima da media\n");

printf("\n----------------------------\n");
printf("\nDigite uma opcao desejada: ");

scanf("%d",&opcao);
funcionario equipe[tam]={
		{"Bernado",12.50,8},
		{"Carlos",10.25,8},
		{"Lucas",11.50,8},
		{"Diego",9.95,8},
};
	switch(opcao)
	{
		case 1:
			ordenaSelectionNome(equipe,tam);
			printf("\nDigite o nome que deseja busca: ");
			scanf("%s",&nomeBusca);
			setbuf(stdin, NULL);
			
			resposta = buscaBinaria(equipe,tam,nomeBusca);
			if(resposta == -1){
				printf("\n----------------------------\n");
				printf("Funcionario não encontrado");
			}else{
				printf("\n----------------------------\n");
				printf("Funcionario encontrado\n");
				printf("Nome: %s, Valor hora trabalhada: %.2f",equipe[resposta].nome,equipe[resposta].valor_hr_trab);
			}
		break;
		case 2:
			calcSalario(equipe,tam);
			ordenaSelectionSalario(equipe,tam);
			exibirMaioresSalarios(equipe,tam);
		break;
		case 3:
			mediaHoraSalario = calcMediaHoraSal(equipe,mediaHoraSalario,tam);
			merge_sort(equipe,0,tam-1);
			ganha_acima_mediaHr(equipe,mediaHoraSalario,tam);	
		break;
		default:
			printf("erro");
		break;
	
	}
return 0;
}


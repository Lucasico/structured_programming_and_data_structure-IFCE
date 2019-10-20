
#include <stdio.h>
#include <string.h>
//struct funcionario
typedef struct funcionario{
	char nome[30];
	int ano,mes,dia;
}funcionario;
funcionario turma[3];
//função com ponteiro do tipo de funcionario
funcionario ordenaFuncionario(funcionario *funcs,int tam);
funcionario *buscaData(int n, funcionario *v,int dia, int mes, int ano);
	
int main(){
	int tam = sizeof(turma) / sizeof(funcionario);
	int ano = 2001,mes = 1, dia = 1,i;
//preenchimento do Struct funcionario.
funcionario pessoa[3]={
	{"Aldenor",2010,3,5},
	{"Cilas",2001,1,1},
	{"Bruna",1998,11,9},
};
//chamadas das funções
ordenaFuncionario(pessoa,tam);
funcionario *resposta = buscaData(tam,pessoa,dia,mes,ano);
	if(resposta == NULL){
		printf("Data nao encontrada");
	}else{
		printf("\nData encontrada. Pessoa: %s",resposta->nome);
	}
 return 0;
}
funcionario ordenaFuncionario(funcionario *pessoa, int tam){
	int i,j;
	for(i = 0;i < tam; i++){
		int menor = i;
		for(j = i + 1; j < tam; j++){
			if(pessoa[j].ano < pessoa[menor].ano)
				menor = j;
			else if(pessoa[j].ano == pessoa[menor].ano && pessoa[j].mes < pessoa[menor].mes)
				menor = j;
			else if(pessoa[j].ano == pessoa[menor].ano && pessoa[j].mes == pessoa[menor].mes && pessoa[j].dia < pessoa[menor].dia)
				menor = j;
		}
		if(menor != i){
			funcionario aux = pessoa[menor];
			pessoa[menor] = pessoa[i];
			pessoa[i] = aux;
		}
	}
}
funcionario *buscaData(int n, funcionario *v,int dia, int mes, int ano){
	int inicio = 0,meio,fim = n - 1;
		while(inicio <= fim){
			meio = (inicio + fim) / 2;
			if(dia < v[meio].dia || mes < v[meio].mes || ano < v[meio].ano){
				fim = meio - 1;
			}else if(dia > v[meio].dia || mes > v[meio].mes || ano > v[meio].ano){
				inicio = meio + 1;
			}	
			else{
				return &v[meio];
			}
		}
	return NULL;
}

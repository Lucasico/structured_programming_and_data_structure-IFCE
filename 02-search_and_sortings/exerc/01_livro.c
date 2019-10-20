
#include <stdio.h>
#include <string.h>

//struct funcionario
typedef struct funcionario{
	char nome[30];
	int val_ht, hora_tr;
}funcionario;
funcionario turma[3];
//função com ponteiro do tipo de funcionario
funcionario *buscaBinary(funcionario v[], int tam, char *nome);
funcionario ordenaFuncionario(funcionario *funcs,int tam);	
int main(){
	int tam = sizeof(turma) / sizeof(funcionario);
	char nome [] = "cilas";
	//preenchimento do Struct funcionario.
	 funcionario funcs[3]={
		{"Aldin",5,40},
		{"cilas",15,50},
		{"duda",8,60},
	};
//ponteiro que recebe o endereço de memoria 
ordenaFuncionario(funcs,tam);
funcionario *resposta = buscaBinary(funcs,tam,nome);
	
	//verificação dos valores recebidos.
 if(resposta == NULL){
 	printf("Funcionario nao encontrado");
 }else{
 	printf("\n%s\n",resposta -> nome);// duas formas de mostra as informações vinda do ponteiro...
 //	printf("%s\n",(*resposta).nome);
 }
 return 0;
}
funcionario ordenaFuncionario(funcionario *funcs, int tam){
	int i,j,menor;
	funcionario aux;
	for(i = 0; i < tam; i++){
		menor = i;
		for(j = i + 1; j < tam; j++){
			if(strcmp(funcs[j].nome, funcs[menor].nome) < 0){
				menor = j;
			}
		}
		funcionario aux = funcs[menor];
		funcs[menor] = funcs[i];
		funcs[i] =  aux;
	}
	for(i = 0; i < tam; i++){
		printf("%s\n",funcs[i].nome);
	}
}
funcionario *buscaBinary(funcionario v[], int tam, char *nome){
	int inicio = 0, fim = tam - 1;
	//algoritmo de busca binaria, com inicio,meio,fim....
	while(inicio <= fim){
		int meio = (inicio + fim) / 2;
		if(strcmp(nome, v[meio].nome) > 0){
			inicio = meio + 1;
		}else if(strcmp(nome, v[meio].nome) < 0){
			fim = meio - 1;
		}else{
			printf("Achou");
			return &v[meio];//retorna o endereço de memoria da posiçaõ encontrada
		}
	}
	return NULL;
}

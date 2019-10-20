
#include<stdio.h>
#include<string.h>

typedef struct pessoa{
	char nomes[30];
	int idade;
	
}pessoas;
//cria��o com "apelido", para a estrutura criada...
pessoa qtd[4];
void ordenaNames(pessoa *names, int qtd){
	int i,j;
	pessoa aux;//cria essa variavel auxiliar do tipo do struct que foi criado
	for(i = 1; i < qtd; i++){
		aux = names[i];	
		//Agora a variavel que foi criada recebe o struct na posi��o[i]
		j = i - 1;
		/*
			move os elementos do vetor, que s�o menores que aux, para
			uma posi��o � frente da sua posi��o atual
		*/
								//A		>		//B retorna > 0
								//A		<		//B retorna < 0
								//A		==		//B retorna == 0
		while(j >= 0 && strcmp(names[j].nomes,aux.nomes) > 0){
			names[j+1] = names[j];
			j = j - 1;
			//aqui ocorre a troca de posi��es com repeti��o
		}
		names[j + 1] = aux;
			//aqui elimina as repeti��es..
	}
}
int main(){
	pessoa[4]={
		{"Luzia","10"},
		{"Bruna"},
		{"Anderson"},
		{"Carla"},
	};
	//preenchi o struct direto para n�o ter que ficar digitado...
	int qtd = 4;
	ordenaNames(nomes,qtd);
	printf("== Estrutura ordenada ==\n");
	for(int i = 0; i < qtd; i++){
		printf("Nomes:%s\n",nomes[i].nomes);
	}
 return 0;
}

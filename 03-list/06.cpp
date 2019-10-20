#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define TAM 7
void exibir(int *vetor){	
	printf("\n");
	for(int i = 0; i < TAM; i++){
		printf(" | %d | ",vetor[i]);
	}
}
void quick_sort(int vetor[TAM],int inicio,int fim){
	int pivo,esq,dir,meio,aux,troca = 0;
	
	//limites da esquerda e da direita
	esq = inicio;
	dir = fim;
	//ajustando auxiliares do centro
	
	meio = (int)((esq + dir) / 2);
	pivo = vetor[inicio];
	
	while(dir > esq){
		while(vetor[esq] < pivo){
			esq = esq + 1;
		}
		while(vetor[dir] > pivo){
			dir = dir - 1;
		}
		
		if(esq <= dir){
			//realizando as trocas
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
		
			
			//faz os limites laterais caminharem para o centro
			esq = esq + 1;
			dir = dir - 1;
			exibir(vetor);
		
		}
		

	}
	//recursão para continuar ordenando
	if(inicio < dir){
		quick_sort(vetor,inicio,dir);
	}if(esq < fim){
		quick_sort(vetor,esq,fim);
	} 
	
}
void merge(int *vetor, int indiceEsquerdo,int meio, int indiceDireito){
	//cria tamanho dos vetores auxiliares
	int n1 = meio - indiceEsquerdo + 1;//tam do vetor da esquerda
	int n2 = indiceDireito - meio;//tam do vetor da direita

//	printf("Inicio = %d, Meio = %d, Fim = %d\n",indiceEsquerdo,meio,indiceDireito);
//	printf("n1 = %d,n2 = %d\n",n1,n2);

	//criando vetores auxiliares
	int vetorEsquerdo[n1], vetorDireito[n2];
	//auxiliares contadores
	int i,j,k;
	//passa os elementos do vetor principal para o vetor da esquerda
	for(i = 0; i < n1; i++){
		vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
	}
	//passa os elementos do vetor principal para o vetor da direita
	for(j = 0; j < n2; j++){
		vetorDireito[j] = vetor[meio + 1 + j];
	}
	//zerando valores das variaveis auxiliares
	
	i = 0; j = 0; k = indiceEsquerdo;

	while(i < n1 && j < n2){
		/*
			caso o valor na esquerda seja menor
			passo para o vetor principal o valor menor
			incrementa o valores auxiliares
		*/
		if(vetorEsquerdo[i] <= vetorDireito[j]){
			vetor[k] = vetorEsquerdo[i];
			i++;
		}else{
			vetor[k] = vetorDireito[j];
			j++;
		}
		
		k++;//almenta o indice de posicionamento do vetor principal
			exibir(vetor);
	}
	
	/*
		se faltarem alguns elementos do vetor do array esquerdo passa eles
		para o array principal.
	*/
	while(i < n1){
		vetor[k] = vetorEsquerdo[i];
		i++;
		k++;
	}
	/*
		se faltarem alguns elementos do vetor do array direito passa eles
		para o array principal.
	*/
	while(j < n2){
		vetor[k] = vetorDireito[j];
		j++;
		k++;
	}
	
	
}
void merge_sort(int *vetor,int indiceEsquerdo, int indiceDireito){
	if(indiceEsquerdo < indiceDireito){
		//Encontra o meio do vetor original..
		int meio = indiceEsquerdo +(indiceDireito - indiceEsquerdo) / 2;
		//Da metade para trás do vetor original
		merge_sort(vetor,indiceEsquerdo,meio);
		//da metade para frente do vetor original
		merge_sort(vetor,meio + 1, indiceDireito);
		//chamada da função para unir os sub-vetores criados com a devida ordenação
		merge(vetor,indiceEsquerdo,meio,indiceDireito);
	}
}
int main(){
int vetor[TAM] = {10,1,11,2,3,16,32};
int vetor2[TAM] = {10,1,11,2,3,16,32};

printf("Quick Sort: \n");
quick_sort(vetor,0,TAM);
printf("\nMergen Sort: \n");
merge_sort(vetor2,0,TAM-1);

return 0;
}


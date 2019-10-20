#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
#define TAM 7
int qtdTrocasMerge = 0;
int qtdtrocasQuick = 0;
/*
	Por se tratar de fun��es com recursividade para contabilizar as trocas as
	as variaveis devem ser declaradas como globais..
*/
void merge(int *vetor, int indiceEsquerdo,int meio, int indiceDireito){
	//cria tamanho dos vetores auxiliares
	int n1 = meio - indiceEsquerdo + 1;//tam do vetor da esquerda
	int n2 = indiceDireito - meio;//tam do vetor da direita
	//criando vetores auxiliares
	int vetorEsquerdo[n1], vetorDireito[n2];
	//auxiliares contadores
	int i,j,k;
	//passa os elementos do vetor principal para o vetor da esquerda
	//  printf("esquerda = %d\n",indiceEsquerdo);
	for(i = 0; i < n1; i++){
		vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
	}
	//passa os elementos do vetor principal para o vetor da direita
	//printf("meio = %d\n",meio);
	for(j = 0; j < n2; j++){
		vetorDireito[j] = vetor[meio + 1 + j];
		//	int x = meio + 1 + j;
		//	printf("Do laco J : %d\n",j);
		//	printf("posi�ao do vetor meio + 1 + j: %d\n",x);
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
			qtdTrocasMerge++;
			
		}else{
			vetor[k] = vetorDireito[j];
			j++;
			//printf("J: %d\n",j);
		}
		k++;//almenta o indice de posicionamento do vetor principal
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
		//printf("Antes: %d, %d\n",indiceEsquerdo,meio);
		merge_sort(vetor,indiceEsquerdo,meio);
		//da metade para frente do vetor original
		merge_sort(vetor,meio + 1, indiceDireito);
		//chamada da fun��o para unir os sub-vetores criados com a devida ordena��o
		merge(vetor,indiceEsquerdo,meio,indiceDireito);
	}
}
void quick_sort(int vetor[TAM],int inicio,int fim){
	int pivo,esq,dir,meio,aux;
	
	//limites da esquerda e da direita
	esq = inicio;
	dir = fim;
	//ajustando auxiliares do centro
	meio = (int)((esq + dir) / 2);
	pivo = vetor[meio];
	
	while(dir > esq){
		while(vetor[esq] < pivo){
			esq = esq + 1;
		}
		while(vetor[dir] > pivo){
			dir = dir - 1;
		}
		if(esq <= dir){
			//realizando as trocas
			qtdtrocasQuick++;
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
			//faz os limites laterais caminharem para o centro
			esq = esq + 1;
			dir = dir - 1;
		}
	}	
	//recurs�o para continuar ordenando
	if(inicio < dir){
		quick_sort(vetor,inicio,dir);
	
	}if(esq < fim){
		quick_sort(vetor,esq,fim);	
	} 
}
int main(){
 int vetorMerge[TAM] = {10,1,11,2,3,16,32};
 int vetorQuick[TAM] = {10,1,11,2,3,16,32};

 merge_sort(vetorMerge,0,TAM-1);
 quick_sort(vetorQuick,0,TAM-1);
 
 printf("--------------------------Exibindo quantidade de trocas-------------------------\n");
 printf("Quantidade de trocas Mergen: %d",qtdTrocasMerge);
 printf("\nQuantidade de trocas Quick: %d",qtdtrocasQuick);
return 0;
}


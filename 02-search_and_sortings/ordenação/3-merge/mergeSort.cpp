#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define tam 7
int qtdTrocasMerge;
void imprimeVetor(int *vetor){
	int i; 
	printf("Vetor: \n");
	for(i = 0;i < tam;i++){
		printf(" %d ",vetor[i]);
	}
	printf("\n");
}
/*
	função recursiva para sub-dividir 
	o vetor original em partes indivisiveis
*/
void merge(int *vetor, int indiceEsquerdo,int meio, int indiceDireito){
	//cria tamanho dos vetores auxiliares

	int n1 = meio - indiceEsquerdo + 1;//tam do vetor da esquerda
	int n2 = indiceDireito - meio;//tam do vetor da direita

//	printf("Inicio = %d, Meio = %d, Fim = %d\n",indiceEsquerdo,meio,indiceDireito);
//  printf("n1 = %d,n2 = %d\n",n1,n2);

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
		//	printf("posiçao do vetor meio + 1 + j: %d\n",x);
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
		int meio = indiceEsquerdo + (indiceDireito - indiceEsquerdo) / 2;
		//Da metade para trás do vetor original
		//printf("Antes: %d, %d\n",indiceEsquerdo,meio);
		merge_sort(vetor,indiceEsquerdo,meio);
		//printf("Depois: %d, %d\n",indiceEsquerdo,meio);
		//da metade para frente do vetor original
		merge_sort(vetor,meio + 1, indiceDireito);
		//printf("Depois: %d, %d\n",meio,indiceDireito);
		//chamada da função para unir os sub-vetores criados com a devida ordenação
		merge(vetor,indiceEsquerdo,meio,indiceDireito);
	}
}
int main(){
 int vetor[tam] = {10,1,11,2,3,16,32};
 imprimeVetor(vetor);
 
 merge_sort(vetor,0,tam-1);
 
 imprimeVetor(vetor);
 printf("\nQuantidade de trocas: %d",qtdTrocasMerge);
return 0;
}


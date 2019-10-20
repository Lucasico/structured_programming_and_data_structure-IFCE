#include<stdio.h>
void insertionSort(int *vet,int tam){
	int j,i,aux,cont;
	for(i = 1; i < tam;i++){
		 aux = vet[i];
		 j = i - 1;
		 
		 while(j >= 0 && vet[j] > aux)
		 {
		 	vet[j+1] = vet[j];
		 	j = j - 1;
		 	cont++;
		 }
		 vet[j + 1] = aux;	
	}
	 printf("QTD de trocas: %d ",cont);
}
int main(){
	int vet[] = {72,12,62,69,27,67,41,56,33,74},tam = sizeof(vet)/sizeof(vet[0]);
	
	insertionSort(vet,tam);
	return 0;
}

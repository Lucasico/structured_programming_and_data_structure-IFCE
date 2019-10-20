#include<stdio.h>
void insertionSort(int *vet,int tam){
	int j,i,aux;
	for(i = 1; i < tam;i++){
		 aux = vet[i];
		 j = i - 1;
		 while(j >= 0 && vet[j] > aux)
		 {
		 	vet[j+1] = vet[j];
		 	j = j - 1;
		 }
		 vet[j + 1] = aux;	
	}
}
int main(){
	int vet[] = {3,25,1,2,4,5,6},tam = sizeof(vet)/sizeof(vet[0]);
	
	insertionSort(vet,tam);
	for(int i = 0; i < tam;i++){
		printf(" %d ",vet[i]);
	}
	return 0;
}

/*1) Implemente o algoritmo de ordenação bolha 
em uma uma função que receba 5 parâmetros: o 
vetor a ser ordenado, o tamanho dele e mais 3 
variáveis para receber os 3 maiores números após 
a ordenação. Os 3 últimos parâmetros devem ser 
preenchidos após a ordenação com os respectivos 
3 maiores valores do valor de inteiros.*/
#include <stdio.h>
void ordenabuble(int *v,int tam,int *mai1, int *mai2, int *mai3){
	int i,j,a,aux;
	for(i=0;i<tam;i++){
		for(j=0;j<tam-1;j++){
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}	
	}
	*mai1 = v[tam-3];
	*mai2 = v[tam-2];
	*mai3 = v[tam-1];
	
	for(a=0;a<tam;a++){	
		printf("%3d",v[a]);
	}
}
int main(){
	int v[5] = {4,2,6,5,1};
	int tam=5,mai1,mai2,mai3;
	ordenabuble(v, tam,&mai1,&mai2,&mai3);
	printf("\n================\n");
	printf("\nOs 3 maiores numeros do vetor sao: %d - %d - %d",mai1,mai2,mai3);
	return 0;
}

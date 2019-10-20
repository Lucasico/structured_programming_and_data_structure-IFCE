#include <stdio.h>
int main(){
	int v[] = {72,16,62,69,27,67,41,56,33,74};
	int tam = 10,i,j,aux,cont;
	for(i=0;i<tam;i++){
		for(j=0;j<tam-1-i;j++){
			if(v[j] > v[j+1] ){
				aux = v[j];
				v[j] = v[j+1]; //comparações
				v[j+1] = aux;
				
			}
			cont++;//trocas
		}
	}
	printf("%d",cont);
	return 0;
}

/*3. Aplique o algoritmo da bolha em uma string,
 ordenando as letras em ordem crescente.*/

#include <stdio.h>
int main(){
	int v[5] = {'b','d','a','e','c'};
	int tam = 5,i,j,aux,a,continua = 0;
	for(i=0;i<tam;i++){
		continua = 0;
		for(j=0;j<tam-1-i;j++){
			if(v[j] > v[j+1] ){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				continua = 1;
			}
		}
			if(continua == 0){
				break;
			}
		for(a=0;a<tam;a++){
			printf("%5c",v[a]);	
		}
			printf("\n");
	}
	return 0;
}


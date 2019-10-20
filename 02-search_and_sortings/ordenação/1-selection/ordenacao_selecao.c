#include <stdio.h>
void ordena(int *v, int tam){
	int i,j,aux;
	//for que procura o menor valor no vetor.
	for(i = 0; i < tam;i++){
		int menor = i;
		for(j = i +1; j < tam; j++){
			if(v[j] < v[menor]){ //compara o termo do frente com o menor valor.
				menor = j; //se a condição for atendida o menor recebe o j.
			}
		}
		//se o menor for diferente do i, ele faz a troca.
		if(menor != i){
			aux = v[menor]; 
			v[menor] = v[i];
			v[i] = aux;	
		}
	}
	//for pra imprimir o vetor ordenado.
	for(i = 0; i < tam;i++){
	printf("%5d",v[i]);
	}	
}
int main(){
	int v[7] = {7,2,1,5,6,9,8};
	int tam = 7,menor;
	ordena(v,tam);
	return 0;
}

/*
Usando recursividade, calcule a soma de
todos os valores de um array de inteiros
Caso base 
	 tamanho do array = 0; soma = 0
Caso geral 
 	 v[n-1] + soma(v, n-1)
*/

    #include<stdio.h>//função de entrada e saida
    #include<locale.h>//função de idioma
    #include<math.h>//função matemÃ¡ticas
    #include<string.h>//função de string
    #include<stdlib.h>//função controle de sistema

int somavetor(int vet[],int tamanho){
    if(tamanho == 0){
        return vet[0];
    }else{
        return somavetor(vet,tamanho - 1) + vet[tamanho];
        /*eu tou dizendo que o vetor na posição[tamanho-1] = 2
        + somavetor(vet,tamanho-1), ate a condição de parada ser satisfeita.
        Pois na verdade vou ta retornando o vetor[0] = soma dos elementos no IF.
        */
    }
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    int vet[]={1,2,3,5},soma;
    soma = somavetor(vet,4);

    printf("soma dos elementos do vetor = %d\n",soma);
	system("pause");//pausa sistema apos execução
	return 0;
}

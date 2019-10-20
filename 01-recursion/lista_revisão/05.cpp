/*
Crie um struct para guardar dados de carros de uma
concessionaria. Cada carro possui uma marca, modelo, ano de
fabricação, preço. Faça buscas no array que guarda os dados
mostrando os carros, por exemplo, da marca ‘toyota’, ano de
fabricação = 2015 e preço < 60000.
*/
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
#define tamVetor 2
typedef struct conce{
	char marca[30],modelo[20];
	int anoFab;
	float preco;
}concessionaria;

concessionaria quantidade[tamVetor];
void funcBuscaVeic(concessionaria veic[],int tamanho){
	for(int i = 0; i < tamanho; i++){
		if(veic[i].anoFab >= 2015 && veic[i].preco <= 60000){
			printf("marca: %s",veic[i].marca);
			printf("modelo: %s",veic[i].modelo);
			printf("ano: %d\n",veic[i].anoFab);
			printf("preço: %.2f\n",veic[i].preco);
			printf("\n------------\n");
		}
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
   	for(int i = 0; i < tamVetor; i++){
   		printf("Digite a marca do veiculo %d: ",i+1);
		fgets(quantidade[i].marca,sizeof(quantidade[i].marca),stdin);
		setbuf(stdin,NULL);

		printf("Digite o modelo do veiculo %d: ",i+1);
		fgets(quantidade[i].modelo,sizeof(quantidade[i].modelo),stdin);
		setbuf(stdin,NULL);

		printf("Digite o ano de fabricação do veiculo %d: ",i+1);
		scanf("%d",&quantidade[i].anoFab);

		printf("Digite o preço do veiculo %d: ",i+1);
		scanf("%f",&quantidade[i].preco);
		setbuf(stdin,NULL);
		printf("\n ------------------- \n");

	}
	funcBuscaVeic(quantidade,tamVetor);

	system("pause");//pausa sistema após execução
	return 0;
}



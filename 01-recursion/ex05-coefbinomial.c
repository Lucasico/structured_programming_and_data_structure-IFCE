
    #include<stdio.h>//funções de entrada e saida
    #include<locale.h>//funções de idioma
    #include<math.h>//funções matemáticas
    #include<string.h>//funções de string
    #include<stdlib.h>//funções de controle de sistema

int binomial(int n,int k){

    if(k == 0 || n == k)
    {
            return 1;
    }
    else
    {
            return binomial(n-1,k) + binomial(n-1,k-1);
    }
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int n,k,exibir;
    printf("\nQuantas maneiras K podem ser escolhidas de N?\n\n");
	printf("Digite o primeiro valor (n): ");
        scanf("%d",&n);
    printf("Digite o segundo valor (k): ");
        scanf("%d",&k);

     exibir = binomial(n,k);

     printf("\nO coeficiente binomial C(n,k) é: %d\n",exibir);

	system("pause");//pausa sistema após execução
	return 0;
}

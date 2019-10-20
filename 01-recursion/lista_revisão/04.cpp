
/*
Crie um struct para representar um compromisso de uma agenda.
Cada compromisso possui um texto que descreve o que irá ser
feito; um local onde ocorrerá; uma data (dia, mês, ano) e um
horário (hora, minutos, segundos).
*/

#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
typedef struct date{
	int dia,mes,ano;
}date;
typedef struct agenda{
	date data;
	int hora,min,segundo;
	char compromisso[250];
}agenda;
void funcPreencher(agenda compromisso[],int qtdVetor){
	for(int i = 0; i < qtdVetor;i++){
		printf("Digite o compromisso: ");
			setbuf(stdin,NULL);
			
		fgets(compromisso[i].compromisso,sizeof(compromisso[i].compromisso),stdin);
			setbuf(stdin,NULL);
			
		printf("Digite o dia do compromisso: ");
			scanf("%d",&compromisso[i].data.dia);
			
		printf("Digite o mes do compromisso: ");
			scanf("%d",&compromisso[i].data.mes);
			
		printf("Digite o ano do compromisso: ");
			scanf("%d",&compromisso[i].data.ano);
			
		printf("Digite a hora do compromisso: ");
			scanf("%d",&compromisso[i].hora);
			
		printf("Digite os minutos do compromisso: ");
			scanf("%d",&compromisso[i].min);
			
		printf("Digite os segundos do compromisso: ");
			scanf("%d",&compromisso[i].segundo);
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
	int qtdCompromisso;
	agenda compromisso[qtdCompromisso];
	
    printf("Digite a quantidade de compromissos: ");
    scanf("%d",&qtdCompromisso);
    
	funcPreencher(compromisso,qtdCompromisso);
	
	system("pause");//pausa sistema após execução
	return 0;
}




#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

void contrario(char s[])
{
	if(s[0] != '\0')
	{
		contrario(&s[1]);
		printf("%c",s[0]);
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    char s[30];
    int t;
    
    printf("Imprime reverso\n\n");
    
    printf("Digite a String: ");
    gets(s);
    
    contrario(s);
	printf("\n\n");
	system("pause");//pausa sistema após execução
	return 0;
}


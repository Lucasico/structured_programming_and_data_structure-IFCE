
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

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
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}


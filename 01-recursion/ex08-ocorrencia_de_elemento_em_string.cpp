/*
Fazer uma fun��o recursiva que conta o n�mero de
ocorr�ncias de um determinado caracter
*/
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

int carac(char c,char s[])
{
	if (s[0] == '\0')
		return 0;
	if (s[0]==c) 
		return carac(c,++s) + 1;
	
	return carac(c,++s);
}
int main()
{
	char s[] = {"lucaas bezerra"},c = 'a';
	int t;
		t=carac(c,s);
		
	printf("\n\nEncontrei %d vezes", t);

return 0;
}


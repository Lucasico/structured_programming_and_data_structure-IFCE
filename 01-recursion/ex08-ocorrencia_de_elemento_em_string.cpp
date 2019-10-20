/*
Fazer uma função recursiva que conta o número de
ocorrências de um determinado caracter
*/
#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema

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


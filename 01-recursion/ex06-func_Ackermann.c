
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema
long int funcAckmann(int m,int n){
    if(m == 0)
    {
        return n + 1;
    }else{
        if(n == 0 && m > 0)
        {
            return funcAckmann(m-1,1);
        }else{

            return funcAckmann(m-1, funcAckmann(m,n-1));
        }
    }

}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    //up-arrow unidade de medida.
    printf("Resultado : %dup-arrow\n\n",funcAckmann(3,0));
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}

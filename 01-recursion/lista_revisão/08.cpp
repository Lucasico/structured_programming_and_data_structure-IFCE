
#include<stdio.h>//fun��es de entrada e saida
#include<locale.h>//fun��es de idioma
#include<math.h>//fun��es matem�ticas
#include<string.h>//fun��es de string
#include<stdlib.h>//fun��es de controle de sistema

typedef struct coor{
	int x;
	int y;
}coordenadas;

coordenadas v1,v2,p;

int dentroRet(coordenadas *v1, coordenadas *v2, coordenadas *p){
	if( ((*v1).x <= (*p).x) && ((*v2).x >= (*p).x) && ((*v1).y <= (*p).y) && ((*v2).y >= (*p).y)){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");//Caracteres especias
    printf("Digite o valor inferior esquerdo: ");
    scanf("%d",&v1.x);
   
    printf("Digite o valor esquerdo inferior: ");
    scanf("%d",&v1.y);
    
	printf("Digite o valor superior esquerdo: ");
    scanf("%d",&v2.x);
    
	printf("Digite o valor esquerdo superior: ");
    scanf("%d",&v2.y);
    
    printf("Coordenada de busca largura: ");
    scanf("%d",&p.x);
    
    printf("Coordenada de busca altura: ");
    scanf("%d",&p.y);
    
    printf("%d\n",dentroRet (&v1,&v2,&p));
	
	system("pause");//pausa sistema ap�s execu��o
	return 0;
}



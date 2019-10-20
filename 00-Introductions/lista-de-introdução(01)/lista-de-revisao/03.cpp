#include<stdio.h>
#include<locale.h>
//fatorial
int main(){
	setlocale(LC_ALL,"portuguese");
	int fat = 1,num;
	
	printf("digite o numero: ");
		scanf("%d",&num);
		for(int i = 1; i <= num; i++){
			fat = fat * i;
				printf("\nO fatorial de %d equivale há: %d\n",i,fat);
			
		}
	
	return 0;
}

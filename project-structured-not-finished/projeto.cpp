#include<stdio.h>//funções de entrada e saida
#include<locale.h>//funções de idioma
#include<math.h>//funções matemáticas
#include<string.h>//funções de string
#include<stdlib.h>//funções de controle de sistema
struct data{
	int dia,mes,ano;
};
struct dt_cheg_prod{
	int dia,mes,ano;
};
struct dt_venc{
	int dia,mes,ano;
};
typedef struct cli{
	char nome[60];
	struct data data_nasc;
	int cpf;
	char endereco[60];
	int fone;
	struct cli* prox;
}cliente;
typedef struct prod{
	char nome[40];
	int qtdChegou;
	int qtdAtual;
	int numLote;
	struct dt_cheg_prod dt_chegada_produto;
	struct dt_venc dt_venciment_lote;
	float precoVenda;
	struct prod* prox;
}produto;
struct dt_venda{
	int dia,mes,ano;
};

cliente *primeiroCliente = (cliente*)malloc(sizeof(cliente));
produto *primeiroProd = (produto*)malloc(sizeof(produto));
produto *primeiro;
void funcoesA();
void funcoesB();
void menuPrincipal(){
	char opcao;
	printf("----- Sistema de Gerenciamento de Cliente, estoque e vendas ----\n");
	printf("A - Funções de Gerenciamento de Cliente\n");
	printf("B - Funções de Gerenciamento de Produtos\n");
	printf("D - Sair do sistema\n");

printf("\nDigite a letra [A][B][D], referente ao\n"
"conjunto de funções desejadas:");
scanf("%c",&opcao);
setbuf(stdin,NULL);

printf("\n");
while(opcao != 'A' && opcao != 'B' && opcao != 'C'&& opcao != 'D'){
	printf("\n Opção digitada invalida digite novamente:");
	scanf("%c",&opcao);
	setbuf(stdin,NULL);
}
system("CLS");
if(opcao == 'A'){
	
	funcoesA();
}
if(opcao == 'B'){
	funcoesB();
}
}
void insereInicio(cli* primeiroCliente,char *nome,int dia,int mes, int ano,int cpf,char *endereco,int fone){
	
		cli* novo = (cli*)malloc(sizeof(cli));
		cli* tmp = primeiroCliente->prox;
		strcpy(novo->nome,nome);
		novo->data_nasc.dia = dia;
		novo->data_nasc.mes = mes;
		novo->data_nasc.ano = ano;
		novo->cpf = cpf;
		strcpy(novo->endereco,endereco);
		novo->fone = fone;
		novo->prox = tmp;
		primeiroCliente->prox = novo;	
}
void exibirClientes(cli *primeiro){
	cli *aux = primeiro->prox;
	int cont = 0;
	while(aux != NULL){
		cont++;
		printf("Dados do %dº cliente\n",cont);
		printf("Nome: %s\n",aux->nome);
		printf("CPF: %d",aux->cpf);
		printf("\n------------------\n");
		aux = aux->prox;
	}
}
cli* Exibir_por_cpf(cli* lista,int cpf){
	cli *aux = lista->prox;
	while(aux != NULL && aux->cpf != cpf){
		aux = aux->prox;
	}
	return aux;
}
int validar_por_cpf(cli* lista, int cpf){
	cli *aux = lista->prox;
	int valida = 0;
	while(aux != NULL ){
		if(aux->cpf == cpf){
			valida = 1;
			return valida;
		}
		aux = aux->prox;
	}
	
	return valida;
}
int valida_por_data(prod* primeiro,int dia_chegada_prod){
	prod *aux = primeiro->prox;
	int valida = 0;
	while(aux != NULL){
		if(aux->dt_chegada_produto.dia == dia_chegada_prod){
			valida = 1;
			return valida;
		}
		aux = aux->prox;
	}
	return valida;
}
void insereProduto(prod* listaProduto, char *nomeProd, int qtdChegou, int qtdAtual, int numLote,int dia_cheg_prod,
int mes_cheg_prod, int ano_cheg_prod, int dia_venc_lote, int mes_venc_lote, int ano_venc_lote, float preco_venda){
	prod* novo = (prod*)malloc(sizeof(prod));
	prod* tmp = listaProduto->prox;
	listaProduto->prox = novo;
	strcpy(novo->nome, nomeProd);
	novo->qtdChegou = qtdChegou;
	novo->qtdAtual = qtdAtual;
	novo->numLote = numLote;
	novo->dt_chegada_produto.dia = dia_cheg_prod;
	novo->dt_chegada_produto.mes = mes_cheg_prod;
	novo->dt_chegada_produto.ano = ano_cheg_prod;
	novo->dt_venciment_lote.dia = dia_venc_lote;
	novo->dt_venciment_lote.mes = mes_venc_lote;
	novo->dt_venciment_lote.ano = ano_venc_lote;
	novo->precoVenda = preco_venda;
	novo->prox = tmp;
	listaProduto->prox = novo;
	
}
void exibirProdutos(prod* listaProdutos){
	prod* aux = listaProdutos->prox;
	int cont = 0;
		printf("\n=-=-=Lista de produtos=-=-=\n");
	while(aux != NULL){
		cont++;
		printf("Dados do %dº produto\n",cont);
		printf("Nome: %s\n",aux->nome);
		printf("Quantidade atual: %d\n",aux->qtdAtual);
		printf("Data de validade do produto: %d/%d/%d\n",aux->dt_venciment_lote.dia,aux->dt_venciment_lote.mes,aux->dt_venciment_lote.ano);
		printf("Preço de venda:%.2f\n",aux->precoVenda);
		printf("=======================\n");
		aux = aux->prox;
	}
}
void excluir_produto_vencido(prod* listaProdutos, int dia,int mes, int ano){
prod* aux = listaProdutos->prox;
	prod* ant = listaProdutos->prox;
	while(aux != NULL){
		if(aux->dt_venciment_lote.ano <= ano){
	      	if(aux->dt_venciment_lote.mes < mes){
	      		ant->prox = aux->prox;
	      		free(aux);
			}else{
				if(aux->dt_venciment_lote.mes == mes){
					if(aux->dt_venciment_lote.dia < dia){
						ant->prox = aux->prox;
	      				free(aux);
					}
				}
			}
		} 
	aux = aux->prox;
	}
}
void exibirProdutosDisponiveis(){
	
	printf("-== Produtos disponiveis com base na data de vencimento ==-\n");
	printf("Data atual: 31/11/2019\n");
	prod* aux = primeiro->prox;
	prod* ant = primeiro->prox;
	while(aux != NULL){
		if(aux->dt_venciment_lote.ano >= 2019){
	      	if(aux->dt_venciment_lote.mes >= 11){
	      		printf("Produto:%s\n",aux->nome);
	      		printf("Preço unitario:%.2f\n",aux->precoVenda);
	      		printf("Quantidade disponivel: %d\n",aux->qtdAtual);
	      		printf("Data de validade:%d/%d/%d\n",aux->dt_venciment_lote.dia,aux->dt_venciment_lote.mes,aux->dt_venciment_lote.ano);
	      		printf("\n");
			}else{
				if(aux->dt_venciment_lote.mes >= 11){
					if(aux->dt_venciment_lote.dia > 31){
						printf("Produto:%s\n",aux->nome);
	      				printf("Preço unitario:%d\n",aux->precoVenda);
	      				printf("Quantidade disponivel: %d\n",aux->qtdAtual);
	      				printf("Data de validade:%d/%d/%d\n",aux->dt_venciment_lote.dia,aux->dt_venciment_lote.mes,aux->dt_venciment_lote.ano);
	      					printf("\n");
					}
				}
			}
		} 
	aux = aux->prox;
	}
}
void funcoesA(){
	int opcaoFuncao,cpf,resultado_cpf;
	char opcaoCliente = 's';
	char nome[60];
	char endereco[60];
	
	cliente *primeiro = primeiroCliente;
	cli *exibir;
	
	do{
		
		printf("= = = Funções para Ger. De Cliente = = =\n");
		printf("[1]-Cadastrar Cliente\n");
		printf("[2]-Mostrar todos os Clientes\n");
		printf("[3]-Buscar Cliente por CPF\n");
		printf("[4]-Realizar pedido Cliente\n");
		printf("[5]-Mostrar últimos 3 pedidos\n");
	
				
		printf("\nDigite a opção referente a operação desejada: ");
		scanf("%d",&opcaoFuncao);
		printf("\n");

		switch(opcaoFuncao){
			case 1:
				strcpy(nome,"Lucas Bezerra");
				strcpy(endereco,"Rua do IFCE");
				printf("Digite o número do CPF: ");
				scanf("%d",&cpf);
				resultado_cpf = validar_por_cpf(primeiro,cpf);
				if(resultado_cpf == 1){
					printf("Cadastro invalido, CPF já cadastrado\n");
				}
				else{
					insereInicio(primeiro,nome,28,3,1998,cpf,endereco,92243980);
					printf("Cadastro realizado com sucesso!\n");
				}
				break;
			case 2:
				exibirClientes(primeiro);
				break;
			case 3:
				printf("Digite o número do CPF do cliente desejado: ");
				scanf("%d",&cpf);
				exibir = Exibir_por_cpf(primeiro, cpf);
				if(exibir == NULL){
					printf("CPF não encontrado\n");
				}else{
					printf("Nome: %s\n",exibir->nome);
					printf("Data de nascimento: %d/%d/%d\n",exibir->data_nasc.dia,exibir->data_nasc.mes,exibir->data_nasc.ano);
					printf("CPF: %d\n",exibir->cpf);
					printf("Endereço: %s\n",exibir->endereco);
					printf("Telefone: %d\n",exibir->fone);
				}
				break;
			case 4:
				printf("Digite o id de verificação == CPF: ");
				scanf("%d",&cpf);
				exibir = Exibir_por_cpf(primeiro, cpf);
				if(exibir == NULL){
					printf("CPF não encontrado\n");
				}else{
					printf("Nome: %s\n",exibir->nome);
					printf("Endereço: %s\n",exibir->endereco);
					exibirProdutosDisponiveis();
					
				}
				break;
			case 5:
				printf("5\n");
				break;
			default:
				break;
		}	
		printf("\nDeseja realizar alguma outra operaçaõ[S][N]: ");
		scanf("%s",&opcaoCliente);
		setbuf(stdin,NULL);
		printf("\n");
		system("CLS");
	}while(opcaoCliente != 'N' && opcaoCliente != 'n');
	menuPrincipal();
}
void funcoesB(){
	int opcaoFuncao,resultado_data,dia_chegada_prod;
	char opcaoProduto = 's';
	char nomeProd[40];
	primeiro = primeiroProd;
	produto *exibirData;

	do{
		printf("= = = Funções para Ger. De Produtos = = =\n");
		printf("[1]-Cadastrar Produto que chegou\n");
		printf("[2]-Lista produtos(Nome,Quant.Atual,Preço de venda)\n");
		printf("[3]-Buscar produtos vencidos\n");
		
		printf("\nDigite a opção referente a operação desejada: ");
		scanf("%d",&opcaoFuncao);
		printf("\n");
		
		switch(opcaoFuncao){
			case 1:
				strcpy(nomeProd,"Cuscuz");
				printf("Digite o dia da chegado do produto: ");
				scanf("%d",&dia_chegada_prod);
				resultado_data = valida_por_data(primeiro,dia_chegada_prod);
				if(resultado_data == 1){
					printf("Cadastro invalido,PRODUTO já cadastrado");
				}else{
					insereProduto(primeiro,nomeProd,40,20,4,dia_chegada_prod,05,2019,20,10,2020,4.20);
					strcpy(nomeProd,"Feijão");
					insereProduto(primeiro,nomeProd,10,20,4,dia_chegada_prod,07,2019,25,11,2019,5.20);
					strcpy(nomeProd,"Refrigerante");
					insereProduto(primeiro,nomeProd,22,20,4,dia_chegada_prod,05,2019,31,12,2019,2.20);
					strcpy(nomeProd,"Arroz");
					insereProduto(primeiro,nomeProd,25,20,4,dia_chegada_prod,05,2019,31,12,2019,3.80);
					strcpy(nomeProd,"Acuçar");
					insereProduto(primeiro,nomeProd,25,20,4,dia_chegada_prod,05,2019,21,12,2020,4.00);
					strcpy(nomeProd,"Margarina");
					insereProduto(primeiro,nomeProd,5,20,4,dia_chegada_prod,05,2019,30,12,2019,2.00);
					strcpy(nomeProd,"Carne Enlatada");
					printf("Produto cadastrado com Sucesso!\n");
				}
				break;
			case 2:
				exibirProdutos(primeiro);
				break;
			case 3:
				excluir_produto_vencido(primeiro,31,11,2019);
				break;
			default:
				printf("ERRO!");
				break;
		}
		printf("\nDeseja realizar alguma outra operaçaõ[S][N]: ");
		scanf("%s",&opcaoProduto);
		setbuf(stdin, NULL);
		printf("\n");
		system("CLS");
	}while(opcaoProduto != 'N' && opcaoProduto != 'n');
	menuPrincipal();
}
int main(){
setlocale(LC_ALL, "Portuguese");
prod* lista = (prod *)malloc(sizeof(prod));

primeiroCliente->prox = NULL;
primeiroProd->prox = NULL;
menuPrincipal();

return 0;
}


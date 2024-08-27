#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pela string

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//inicio cri��o de vari�veis/strings
	char arquivo [40];//strings
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rios
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar as strings
	
	FILE *file; // cria o arquivo no banco de dados 
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobre nome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); //Definido a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!./n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()//Fun�ao main
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		setlocale(LC_ALL,"portuguese"); //2Definido a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");//fim  do menu
		printf("Op��o ");
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");//respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel\n");
			system("pause");
			break;
				
		}// fim da sele��o
	
	}
}

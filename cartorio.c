#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável pelas strings

int registro() //Função responsável por cadastrar usuários no sistema
{
	//Início da criação de variáveis(strings)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis(strings)
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo //"w" significa "escrever"
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}
	
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file==NULL)
	{
		printf("Não foi possível abrir o arquivo (não localizado)!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
}


int main ()
	{
	int opcao=0;//Definindo variáveis
	int i=1;
	
	for(i=1;i=10;)
	{
	
	
		system("cls");//Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
		
		printf ("### Registro de alunos do cartório EBAC ###\n\n");//Inicio do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Resgistrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Opção: ");//Fim do menu
		
		scanf ("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();//Chamada de funções
			break;
			
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
				
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		}//Fim da seleção
	
}
}

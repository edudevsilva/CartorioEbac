#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria. Permite criar e manipular arquivos no nosso computador.
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coketando informa��es do usu�rio
	scanf("%s", cpf); // "%s" refere-se a string, usado para salvar strings
	
	strcpy(arquivo, cpf); //Respons�vel por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" � de write, i.e., cria e j� escreve
	fprintf(file,cpf); //salva o valor da vari�vel
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
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}


int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200]; //Resposta da pesquisa, o conte�do das informa��es do usu�rio
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //Guarda a resposta do usu�rio do programa e pesquisa o cpf (vari�vel cpf) digitado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o localizado. \n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //ENQUANTO houver conte�do no arquivo aberto, ou seja, enquanto houverem informa��es referentes ao CPF pesquisado, ele armazenar� na vari�vel "conte�do" at� 200 caracteres, enquanto o valor da pesquisa for diferente de nulo, de acordo com a linha de c�digo anterior
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //Pedindo pra mostrar ao usu�rio do app o que ficou salvo na string da vari�vel "conte�do". Ou seja, o que ficou armazenado na vari�vel "conte�do" eu quero que o usu�rio veja.
		printf("\n\n");		
	}
	
	system("pause");
}


int deletar()

//{
//	printf("Voc� escolheu deletar nomes\n");
//	system("pause");
//}

{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\t\tCart�rio da EBAC \n\n"); //In�cio do Menu
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t1 - Registrar Nomes \n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n");
		printf("\t4 - Sair do Sistema \n\n\n");
		printf("Op��o: ");  //Fim do Menu
	
		scanf("%d", &opcao); //Armzenando a escolha do usu�rio
	
		system("cls"); //fun��o de limpar a tela
		
		switch(opcao) 
		{
			case 1:
			registrar(); //chamada de fun��es
			break;
				
			case 2:
			consultar();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
				printf("Voc� escolheu uma op��o inv�lida\n");
				system("pause");  // Fim da sele��o
		}
	
	}

}

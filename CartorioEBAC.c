#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória. Permite criar e manipular arquivos no nosso computador.
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registrar() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coketando informações do usuário
	scanf("%s", cpf); // "%s" refere-se a string, usado para salvar strings
	
	strcpy(arquivo, cpf); //Responsável por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" é de write, i.e., cria e já escreve
	fprintf(file,cpf); //salva o valor da variável
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
	char conteudo[200]; //Resposta da pesquisa, o conteúdo das informações do usuário
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //Guarda a resposta do usuário do programa e pesquisa o cpf (variável cpf) digitado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, CPF não localizado. \n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //ENQUANTO houver conteúdo no arquivo aberto, ou seja, enquanto houverem informações referentes ao CPF pesquisado, ele armazenará na variável "conteúdo" até 200 caracteres, enquanto o valor da pesquisa for diferente de nulo, de acordo com a linha de código anterior
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //Pedindo pra mostrar ao usuário do app o que ficou salvo na string da variável "conteúdo". Ou seja, o que ficou armazenado na variável "conteúdo" eu quero que o usuário veja.
		printf("\n\n");		
	}
	
	system("pause");
}


int deletar()

//{
//	printf("Você escolheu deletar nomes\n");
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
		printf("O usuário não se encontra no sistema. \n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\t\tCartório da EBAC \n\n"); //Início do Menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - Registrar Nomes \n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n");
		printf("\t4 - Sair do Sistema \n\n\n");
		printf("Opção: ");  //Fim do Menu
	
		scanf("%d", &opcao); //Armzenando a escolha do usuário
	
		system("cls"); //função de limpar a tela
		
		switch(opcao) 
		{
			case 1:
			registrar(); //chamada de funções
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
				printf("Você escolheu uma opção inválida\n");
				system("pause");  // Fim da seleção
		}
	
	}

}

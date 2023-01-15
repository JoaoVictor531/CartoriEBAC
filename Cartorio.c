#include <stdio.h> // se comunica com o usu�rio (comandos printf, scanf, for, etc...)
#include <stdlib.h> // reserva espa�o na mem�ria para as vari�veis
#include <locale.h> // reserva os textos por regi�o 
#include <string.h> // biblioteca responsavel pelas strings


int registrar() // para cada nova fun��o, adicionar os comandos das bibliotacas espec�ficas. 
{
	char arquivo [40]; // A vari�vel "arquivo" ser� criada para nomearmos o nome do arquivo que ser� salvo com o conte�do da vari�vel "CPF"
	char cpf [40]; 			// variavel respons�vel por armazenar a informa��o digitada pelo usu�rio
	char nome [40]; 		// variavel respons�vel por armazenar a informa��o digitada pelo usu�rio
	char sobrenome [40];		// variavel respons�vel por armazenar a informa��o digitada pelo usu�rio
	char cargo [40]; 		// variavel respons�vel por armazenar a informa��o digitada pelo usu�rio
	
	printf("Digite o CPF a ser cadastrado: "); // pede as informa��es ao usu�rio
	scanf("%s", cpf); // armazena as informa��es digitadas pelo usu�rio
	
	strcpy(arquivo, cpf); // linha respons�vel por NOMEAR o arquivo com o conte�do que est� dentro da vari�vel "cpf".
	
	FILE *file; // comando FILE para chamar um arquivo 
	file = fopen(arquivo, "w"); // Comando para abrir o arquivo chamado e "w" p/ indicar que na proxima linha ser� ESCRITO algo DENTRO do arquivo
	fprintf(file, cpf); // comando que escreve dentro do arquivo chamado
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" p/ indicar que o conte�do do arquivo ser� atualizado (ser� adicionado uma nova informa��o
	fprintf(file,", "); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);
	
	system("cls"); // limpa a tela
	
	printf("\tCadastro realizado com sucesso!\n\n"); // confirma��o de cadastro
	system("pause");		
}

int consultar()  // para cada nova fun��o, adicionar os comandos das bibliotacas espec�ficas. 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; 			// variavel respons�vel por armazenar a informa��o digitada pelo usu�rio
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");  // pede informa��o ao usu�rio
	scanf("%s", cpf); 							// armazena a informa��o digitada pelo usu�rio na ri�vel desejada 
	
	FILE *file; 			// comando para chamar um arquivo qualquer 
	file = fopen(cpf,"r"); // comando para abrir o arquivo desejado e "r" para ler o conte�do do arquivo
 
	if(file == NULL) 	// se o dado digitado pelo usu�rio for nulo, ou seja, diferente do CPF que o usu�rio digitou 
	{
		printf("\n\tArquivo n�o localizado! \n\n"); // mostra ao usu�rio caso o cpf digitado nunca tenha sido cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) 	// comando WHILE =  o (FGETS coloca dentro da variavel (conteudo, todos os 200 caracteres, do arquivo file, enquanto o conteudo) for diferente de NULO), ou seja, enquanto houvento conteudo v�lido dentro da vari�vel.  
	{
		printf("\nEssas s�o as informa��es cadastradas: "); 
		printf("%s", conteudo); // todos os caracteres encontarados dentro do arquivo passam a ser atribu�dos � vari�vell conteudo e est�o sendo expostas ao usu�rio agora 
		printf("\n\n"); 
	}
	
	system("pause");
	
	fclose(file); // ap�s todos os passos serem concl�dos, fechamos o arquivo 	
}

int deletar()
{
	char cpf [40]; // variavel respons�vel por armazenar a informa��o digitada pelo usu�rio
		
	setlocale(LC_ALL, "Portuguese"); // comando que valida todos os acentos do idioma escolhido pelo dev
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // pede informa��o ao usu�rio 
	scanf("%s",cpf); // armazena essa informa��o � vari�vel
	
	remove(cpf); // deleta o arquivo de banco de dados 
	
	FILE *file; // inicio da valida��o de exclus�o do arquivo 
	file = fopen(cpf,"r"); // abre o arquivo desejado e "r" para ler o conteudo que est� dentro dele
	
	system("cls");
	
	if(file == NULL) // se o arquivo for igual a nulo, ou seja, se a informa��o que o usuario digitou n�o for encontrada
	{
		printf("\tUsu�rio deletado com sucesso! \n\n"); // confirma��o de exclus�o
	}	
	
	system("pause");
	
}

int main()

{
	int opcao=0; // v�riaveis n�o podem ter acentos 
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("\t### Cart�rio da EBAC ###\n\n"); // n�o iniciar comandos com letra mai�scula!
		printf("Escolha uma op��o do menu: \n\n"); 
		printf("\t1- Registrar  \n"); // "\t" para criar um paragr�fo
		printf("\t2- Consultar \n");
		printf("\t3- Deletar \n\n");
	
		printf("Op��o: "); 
		scanf("%d", &opcao); 

		system("cls"); // Para limpar (trocar de tela)
	
		switch (opcao) // n�o esquecer de indicar a vari�vel ap�s escrever o comando switch
		{
			case 1:
			registrar();
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
		
			default: // n�o esquecer os dois pontos (:) para validar o default
			printf("Esta op��o n�o est� disponivel!\n\n");
			system("pause");
		} 						// fim switch
	}							// fim do la�o	
} 								// fim da main

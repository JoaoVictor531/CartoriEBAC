#include <stdio.h> // se comunica com o usuário (comandos printf, scanf, for, etc...)
#include <stdlib.h> // reserva espaço na memória para as variáveis
#include <locale.h> // reserva os textos por região 
#include <string.h> // biblioteca responsavel pelas strings


int registrar() // para cada nova função, adicionar os comandos das bibliotacas específicas. 
{
	char arquivo [40]; // A variável "arquivo" será criada para nomearmos o nome do arquivo que será salvo com o conteúdo da variável "CPF"
	char cpf [40]; 			// variavel responsável por armazenar a informação digitada pelo usuário
	char nome [40]; 		// variavel responsável por armazenar a informação digitada pelo usuário
	char sobrenome [40];		// variavel responsável por armazenar a informação digitada pelo usuário
	char cargo [40]; 		// variavel responsável por armazenar a informação digitada pelo usuário
	
	printf("Digite o CPF a ser cadastrado: "); // pede as informações ao usuário
	scanf("%s", cpf); // armazena as informações digitadas pelo usuário
	
	strcpy(arquivo, cpf); // linha responsável por NOMEAR o arquivo com o conteúdo que está dentro da variável "cpf".
	
	FILE *file; // comando FILE para chamar um arquivo 
	file = fopen(arquivo, "w"); // Comando para abrir o arquivo chamado e "w" p/ indicar que na proxima linha será ESCRITO algo DENTRO do arquivo
	fprintf(file, cpf); // comando que escreve dentro do arquivo chamado
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" p/ indicar que o conteúdo do arquivo será atualizado (será adicionado uma nova informação
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
	
	printf("\tCadastro realizado com sucesso!\n\n"); // confirmação de cadastro
	system("pause");		
}

int consultar()  // para cada nova função, adicionar os comandos das bibliotacas específicas. 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; 			// variavel responsável por armazenar a informação digitada pelo usuário
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");  // pede informação ao usuário
	scanf("%s", cpf); 							// armazena a informação digitada pelo usuário na riável desejada 
	
	FILE *file; 			// comando para chamar um arquivo qualquer 
	file = fopen(cpf,"r"); // comando para abrir o arquivo desejado e "r" para ler o conteúdo do arquivo
 
	if(file == NULL) 	// se o dado digitado pelo usuário for nulo, ou seja, diferente do CPF que o usuário digitou 
	{
		printf("\n\tArquivo não localizado! \n\n"); // mostra ao usuário caso o cpf digitado nunca tenha sido cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) 	// comando WHILE =  o (FGETS coloca dentro da variavel (conteudo, todos os 200 caracteres, do arquivo file, enquanto o conteudo) for diferente de NULO), ou seja, enquanto houvento conteudo válido dentro da variável.  
	{
		printf("\nEssas são as informações cadastradas: "); 
		printf("%s", conteudo); // todos os caracteres encontarados dentro do arquivo passam a ser atribuídos à variávell conteudo e estão sendo expostas ao usuário agora 
		printf("\n\n"); 
	}
	
	system("pause");
	
	fclose(file); // após todos os passos serem conclídos, fechamos o arquivo 	
}

int deletar()
{
	char cpf [40]; // variavel responsável por armazenar a informação digitada pelo usuário
		
	setlocale(LC_ALL, "Portuguese"); // comando que valida todos os acentos do idioma escolhido pelo dev
	
	printf("Digite o CPF do usuário a ser deletado: "); // pede informação ao usuário 
	scanf("%s",cpf); // armazena essa informação à variável
	
	remove(cpf); // deleta o arquivo de banco de dados 
	
	FILE *file; // inicio da validação de exclusão do arquivo 
	file = fopen(cpf,"r"); // abre o arquivo desejado e "r" para ler o conteudo que está dentro dele
	
	system("cls");
	
	if(file == NULL) // se o arquivo for igual a nulo, ou seja, se a informação que o usuario digitou não for encontrada
	{
		printf("\tUsuário deletado com sucesso! \n\n"); // confirmação de exclusão
	}	
	
	system("pause");
	
}

int main()

{
	int opcao=0; // váriaveis não podem ter acentos 
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("\t### Cartório da EBAC ###\n\n"); // não iniciar comandos com letra maiúscula!
		printf("Escolha uma opção do menu: \n\n"); 
		printf("\t1- Registrar  \n"); // "\t" para criar um paragráfo
		printf("\t2- Consultar \n");
		printf("\t3- Deletar \n\n");
	
		printf("Opção: "); 
		scanf("%d", &opcao); 

		system("cls"); // Para limpar (trocar de tela)
	
		switch (opcao) // não esquecer de indicar a variável após escrever o comando switch
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
		
			default: // não esquecer os dois pontos (:) para validar o default
			printf("Esta opção não está disponivel!\n\n");
			system("pause");
		} 						// fim switch
	}							// fim do laço	
} 								// fim da main

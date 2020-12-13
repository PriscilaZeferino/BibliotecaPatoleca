#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxIndice 3
#define tamanhoChars 50

//clientes
char name [maxIndice][tamanhoChars] = {};
char phone [maxIndice][tamanhoChars] = {};
char cpf [maxIndice][tamanhoChars] = {};

//livros
char titulo [maxIndice][tamanhoChars]={};
char ano [maxIndice][tamanhoChars]={};
char autor [maxIndice][tamanhoChars]={};

//locacao
int livrolocado [maxIndice];
char data_de_entrega [maxIndice][tamanhoChars]={};

//Posicoes ocupadas 
int ocupadoCliente = 0;
int ocupadoLivro = 0;

//Acessar os indices do array
int i = 0;

///**Apagar depois*/
//void CadastrarDadosParaTeste()
//{
//	strcpy(name[ocupadoCliente], "Priscila");
//	strcpy(phone[ocupadoCliente], "9111-1111");
//	strcpy(cpf[ocupadoCliente], "111.111");
//	ocupadoCliente++;
//	
//	strcpy(name[ocupadoCliente], "Tamara");
//	strcpy(phone[ocupadoCliente], "9222-1111");
//	strcpy(cpf[ocupadoCliente], "222.222.222");
//	ocupadoCliente++;
//	
//	strcpy(titulo[ocupadoLivro], "Programar");
//	strcpy(ano[ocupadoLivro], "2020");
//	strcpy(autor[ocupadoLivro], "Zeferino");
//	ocupadoLivro++;
//	
//	strcpy(titulo[ocupadoLivro], "Meditar");
//	strcpy(ano[ocupadoLivro], "2019");
//	strcpy(autor[ocupadoLivro], "Tanembaum");
//	ocupadoLivro++;
//	
//	for(i = 0; i < maxIndice; i++)
//	{
//		livrolocado[i] = -1;
//	}
//	
//}

void MostrarMenu()
{
 	 //Menu
	 printf("\n");
	 printf("MENU---------------------------------\n");
	 printf("0. Sair------------------------------\n");
	 printf("1. Listar Clientes-------------------\n");
	 printf("2. Cadastrar clientes pelo codigo----\n");
	 printf("3. Pesquisar cliente pelo nome-------\n");
	 printf("4. Excluir cliente pelo codigo-------\n");
	 printf("5. Listar livros --------------------\n");
	 printf("6. Cadastrar livro ------------------\n");
	 printf("7. Pesquisar livro pelo nome---------\n");
	 printf("8. Excluir livros pelo codigo--------\n");
	 printf("9. Listar livros locados-------------\n");
	 printf("10.Locar livro-----------------------\n");
	 printf("11.Devolver livro pelo codigo--------\n");
	 printf("\n");
}

void ListarClientes()
{
 	 system("cls");
	 printf("===================LISTA DE CLIENTES===========================\n");
	 printf("CODIGO---------NOME-------------PHONE--------------CPF---------\n");
				
		for(i = 0; i < maxIndice; i++)
		{
			if(strcmp(name[i],"") != 0 || strcmp(phone[i],"") != 0 || strcmp(cpf[i],"") != 0 )
			{
				printf("  %d :		%s		%s			%s", i, name[i], phone[i], cpf[i]);
				printf("\n");
			}
		}	
}

void CadastrarCliente()
{
	//Cadastra o cliente na primeira posicao livre.
 	 if(ocupadoCliente < maxIndice)
	 {
        for(i = 0; i < maxIndice; i++)
        {
        	if(strcmp(name[i], "") == 0 && strcmp(phone[i], "") == 0 && strcmp(cpf[i], "") == 0)
        	{
   			 	printf("Informe o nome do cliente: \n");
				fflush(stdin);
				scanf("%[^\n]", name[i]);
					
				printf("Informe o telefone do cliente: \n");
				fflush(stdin);	
				scanf("%[^\n]", phone[i]);
		
				printf("Informe o cpf do cliente: \n");
				fflush(stdin);
				scanf("%[^\n]", cpf[i]);
				ocupadoCliente++;
				break;
			}
		}
	 }
 	 else
	 {
  	   	 printf("Todas as posicoes estao ocupadas");
     }
}

void ListarLivros()
{
 	 printf("===================LISTA DE LIVROS===============================\n");
	 printf("CODIGO---------TITULO-------------ANO--------------AUTOR---------\n");
	 
	 for(i = 0; i < maxIndice; ++i)
	 {
  	    if(strcmp(titulo[i],"") != 0 || strcmp(ano[i],"") != 0 || strcmp(autor[i],"") != 0 )
		{
			printf("  %d :		%s		%s			%s", i, titulo[i], ano[i], autor[i]);
			printf("\n");
		}
	}
}

void ListarLivrosLocados()
{
	 	 printf("===================LISTA DE LIVROS LOCADOS=======================\n");
		 printf("CODIGO---------TITULO-------------ANO--------------AUTOR---------\n");
		 
		 for(i = 0; i < maxIndice; ++i)
		 {
		  	   if(livrolocado[i] != -1)
		 	   {
  	    	   	   	if(strcmp(titulo[i],"") != 0 || strcmp(ano[i],"") != 0 || strcmp(autor[i],"") != 0 )
				   	{
 						printf("  %d :		%s		%s			%s", i, titulo[i], ano[i], autor[i]);
						printf("\n");
			        }
			   } 
 	     }
}

void CadastrarLivro()
{
	//Cadastra o livro na primeira posicao livre.
 	 if(ocupadoCliente < maxIndice)
	 {
        for(i = 0; i < maxIndice; i++)
        {
        	if(strcmp(titulo[i], "") == 0 && strcmp(ano[i], "") == 0 && strcmp(autor[i], "") == 0)
        	{
   			 	printf("Informe o titulo do livro: \n");
				fflush(stdin);
				scanf("%[^\n]", titulo[i]);
					
				printf("Informe o ano do livro: \n");
				fflush(stdin);	
				scanf("%[^\n]", ano[i]);
		
				printf("Informe o autor do autor: \n");
				fflush(stdin);
				scanf("%[^\n]", autor[i]);
				ocupadoLivro++;
				break;
			}
		}
	 }
 	 else
	 {
  	   	 printf("Todas as posicoes estao ocupadas");
     }
}
int main(int argc, char *argv[]) {
	int stop = 0;
		
	//Recebe os codigos
	int code = -1;
	
	//Para as pesquisas no array
	int encontrado;
	
	int menu;
//	CadastrarDadosParaTeste();
	do
	{
	  	MostrarMenu();
		printf("O que deseja fazer? \n");
		
		fflush(stdin);
		scanf("%d", &menu);
		
		switch(menu)
		{
			//Sair
			case 0:
				break;
			
			//Listar clientes
			case 1:
		 		 ListarClientes();
				 break;
			
			//Cadastrar cliente 
			case 2:
				CadastrarCliente();
				break;	
			
			//Pesquisar cliente pelo nome
			case 3:
				system("cls");
				char nomeEscolhido[tamanhoChars] = "";
				
				printf("PESQUISAR CLIENTE PELO NOME: \n");
				
				printf("Informe o nome do cliente: \n");
				
				fflush(stdin);
				scanf("%[^\n]", nomeEscolhido);
				
				printf("\n");

				encontrado = 0; //1- sim 0 - nao;
				
				for(i = 0; i < maxIndice; i++)
				{
					if(strcmp(nomeEscolhido,name[i]) == 0)
					{
						encontrado = 1;
						code = i; 
					}
				}
				
				if(encontrado == 1)
				{
						printf("CLIENTE ENCONTRADO \n");
						printf("	Codigo: %d   \n", code);
						printf("	Nome: %s	 \n", name[code]);
						printf("	Telefone: %s \n", phone[code]);
						printf("	CPF: %s		 \n", cpf[code]);
				}
				else
				{
					printf("NAO ENCONTRADO");
				}
				
				
			
			break;
				
			//Excluir cliente pelo codigo
			case 4:
				system("cls");
				ListarClientes();
				
				printf("--------------------EXCLUIR CLIENTE----------------------------\n");
				
				stop = 0;
				do 
				{
					printf("Qual o codigo do cliente: (0-%d) \n", (maxIndice-1));
					fflush(stdin);				
					scanf("%d", &code);

					encontrado = 0;
					if(code >= 0 && code < maxIndice)
					{
						
						if(livrolocado[code] == -1)
						{
						   	if(strcmp(name[code], "") != 0 && strcmp(phone[code], "") != 0 && strcmp(cpf[code], "") != 0)
							{
								encontrado = 1;
								stop = 1;
							}
						
					
							if(encontrado == 1)
							{

								strcpy(name[code], name[code+1]);
								strcpy(phone[code], phone[code+1]);	
								strcpy(cpf[code], cpf[code+1]);

								name[code+1][0] = '\0' ;
								phone[code+1][0] = '\0';
								cpf[code+1][0] = '\0';

								printf("CLIENTE EXCLUIDO COM SUCESSO \n");
								ocupadoCliente = ocupadoCliente - 1;
								stop = 1;

			  			    }
							else
							{	
								printf("CLIENTE NAO ENCONTRADO \n");
								stop = 1;
							}	
				  }
						else
						{
							printf("Este cliente tem livro locado. \n");
							printf("Ele precisa devolver antes de ser excluido. \n");
							stop = 1;
						}	
					}
					else
					{
						printf("Codigo invalido! \n");
						stop = 0;
					}
			
			}
			while(stop != 1);
			
			break;
			
			//Listar livros
			case 5:
				system("cls");
				ListarLivros();
				break;
				
			//Cadastrar livro 
			case 6:
				system("cls");
				CadastrarLivro();
			
				break;
				
			//Pesquisar livro pelo nome
			case 7:
				system("cls");
				char tituloLivro[tamanhoChars] = "";
				
				printf("PESQUISAR LIVRO PELO NOME: \n");
				
				printf("Informe o titulo do livro: \n");
				
				fflush(stdin);
				scanf("%[^\n]", tituloLivro);
				
				printf("\n");

				encontrado = 0; //1- sim 0 - nao;
				
				for(i = 0; i < maxIndice; i++)
				{
					if(strcmp(tituloLivro,titulo[i]) == 0)
					{
						encontrado = 1;
						code = i; 
					}
				}
				
				if(encontrado == 1)
				{
						printf("LIVRO ENCONTRADO \n");
						printf("	Codigo: %d   \n", code);
						printf("	Titulo: %s	 \n", titulo[code]);
						printf("	Ano: %s \n", ano[code]);
						printf("	autor: %s	 \n", autor[code]);
				}
				else
				{
					printf("NAO ENCONTRADO");
				}
				
				
			
			break;
				
			//Excluir livro pelo codigo
			case 8:
				system("cls");
				ListarLivros();
				
				printf("--------------------EXCLUIR LIVRO----------------------------\n");
				
				stop = 0;
				do 
				{
					printf("Qual o codigo do livro: (0-%d) \n", (maxIndice-1));
					fflush(stdin);				
					scanf("%d", &code);
				
					if(code >= 0 && code < maxIndice)
					{
						
						if(livrolocado[code] == -1)
						{
						   	if(strcmp(titulo[code], "") != 0 && strcmp(ano[code], "") != 0 && strcmp(autor[code], "") != 0)
							{
								encontrado = 1;
								stop = 1;
							}
						
					
							if(encontrado == 1)
							{
		     				    strcpy(titulo[code], titulo[code+1]);
								strcpy(ano[code], ano[code+1]);	
								strcpy(autor[code], autor[code+1]);

								titulo[code+1][0] = '\0' ;
								ano[code+1][0] = '\0';
								autor[code+1][0] = '\0';

								printf("LIVRO EXCLUIDO COM SUCESSO \n");
								ocupadoLivro = ocupadoLivro - 1;
								stop = 1;
							}
							else
							{	
								printf("LIVRO NAO ENCONTRADO \n");
								stop = 1;
							}	
						}
						else
						{
							printf("Este livro esta locado. \n");
							printf("Ele precisa ser devolvido antes de ser excluido. \n");
							stop = 1;
						}	
					}
					else
					{
						printf("Codigo invalido! \n");
						stop = 0;
					}	
				}
			while(stop != 1);
			
			break;
			
			//Listar livros locados
			case 9:
				system("cls");
				ListarLivrosLocados();
				break;
				
			//locar livro
			case 10:
				system("cls");
				
				stop = 0;
				do 
				{
					int cliente = -1;
					int livro = -1;
					encontrado = 0;
					
				   //Dados do cliente
					ListarClientes();
					printf("Informe o codigo do cliente (0-%d): \n", (ocupadoCliente-1));
					fflush(stdin);
					scanf("%d", &cliente);
					
					if(livrolocado[cliente] == -1)
					{	
						
						//Dados do livro
						system("cls");
						ListarLivros();
						printf("Informe o codigo do livro para locar (0-%d): \n", (ocupadoLivro-1));
						fflush(stdin);
						scanf("%d", &livro);
						
						/**
	 			       	P.S: livrolocado[cliente]
	 		 		   	Guarda o livro na mesma posicao do codigo do cliente
						*/
						for(i = 0; i < maxIndice; i++)
						{
							if(livrolocado[i] == livro)
							{
								printf("Livro ja locado por outro cliente. \n");
								livrolocado[cliente] = -1;
								encontrado = 1;
								stop = 1;
							}
						}
						
						if(encontrado != 1)
						{
							livrolocado[cliente] = livro;

							printf("Informe a data de entrega: \n");
						    fflush(stdin);
				  		    scanf("%[^\n]", data_de_entrega[cliente]);
							
							printf("\n");
							printf("LIVRO LOCADO COM SUCESSO");	
							stop = 1;
						}
					}
					else
					{
						printf("Este cliente ja tem livro locado.");
						printf("Ele precisa devolver antes de locar outro.");
						stop = 1;
					}
					
				}
				while(stop != 1);
			
				break;
				
			//Devolver livro pelo codigo do cliente
			case 11:
				system("cls");	
				stop = 0;
				
				do
				{
					stop = 1;
					ListarClientes();
					printf("Informe o codigo do cliente: \n");
			 		fflush(stdin);
					scanf("%d", &code);

					if(code >=0 && code < maxIndice)
					{
		 			    if(livrolocado[code] != -1)
					 	{
					 	 	livrolocado[code] = -1;
 				 		 	data_de_entrega[code][0] = '\0';
 				 		 	printf("LIVRO DEVOLVIDO COM SUCESSO. \n");
 				 		 	stop = 1;
				    	}
					 	else
						{
 					 	    printf("Este cliente nao tem livro locado. \n");
 					 	    stop = 1;
		 		    	}
					}
				 	else
					{	
				 		printf("Codigo invalido!");
					}
				}
				while(stop != 1);
				break;
				
			default:
				system("cls");
				printf("ENTRADA INVALIDA");
				break;
		}
	
	}
	while(menu != 0);

	/** NOTAS (O QUE FAZER E COISAS PARA CONSERTAR) - DPS APAGO*/

	/*
		
		TO DO...
		
		1  - Listar clientes - OK.
		2  - Cadastrar clientes - OK.
		3  - Pesquisar clientes pelo nome - OK.
		4  - Excluir clientes pelo codigo -OK
		5  - Listar livros - OK.
		6  - Cadastrar livros - OK.
		7  - Pesquisar livros pelo nome - OK.
		8  - Excluir livros pelo codigo - OK
		9  - Listar livros locados - OK
		10 - Locar livro - OK.
		11 - Devolver livro pelo codigo do cliente - Ok
		
		* Trocar o tipo do ano do livro para inteiro
		* Corrigir bugs e falhas
*/
	
	return 0;
}

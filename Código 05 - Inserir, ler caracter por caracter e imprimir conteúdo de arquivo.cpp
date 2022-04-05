/*
    Name: Inserir, atualizar, ler caracter por caracter e imprimir conteúdo de arquivo.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 11 - SISTEMAS DE ARQUIVOS CONCEITOS
    Date: 07/05/2021
    Description: Programa que faz a inserção, atualização, leitura caracter por caracter e impressão do conteúdo do arquivo
                 especificado pelo usuário.
*/

#include <stdio.h>
#include <string.h>

int main() 
{
	FILE *fp; char arq[100];
	do
	{
		printf("\nDigite o nome do arquivo: ");
		fflush(stdin); gets(arq);
	}while(strlen(arq)==0);
	
	fp=fopen (arq,"a+"); // abre para leitura e escrita ao final do arquivo; se o arquivo não existir, ele é criado
	
	if (fp==NULL) 
	{ 
	 	printf ("Erro na abertura do arquivo"); 
 		fclose(fp);
 		return 0;
	}
	
	int op, total; char entrada[100]; char *c, ler;
	do
	{
		do
		{
			printf("\n1 - Criar, atualizar e digitar conteudo	2 - Ler e imprimir	3 - Ler caracter por caracter	4 - Encerrar	--> ");
			scanf("%d",&op);
		}while(op<1 || op>4);
		
		switch(op)
		{
				case 1 : printf("\nDigite suas frases (FIM para sair): \n");
				
						 for(;;) 
						 {
							fflush(stdin); gets(entrada);
							if(strcmp(entrada,"FIM")==0) break;
							strcat(entrada,"\n");
							fprintf(fp,entrada);
 						 }
 						 
 						 rewind(fp); // retorna o ponteiro do arquivo para o início do mesmo
 						 break;
 						 
				case 2 : printf("\nConteudo do arquivo: \n\n");
				
						 while(!feof(fp))
						 {
						 	c = fgets(entrada, 101, fp); // lê uma linha com até 100 caracteres, inclusive \n
						 	if (c) printf("%s",entrada);
 						 }
 						 
 						 rewind(fp);
 						 break;
 						 
				case 3 : while((ler=fgetc(fp))!=EOF) // fgetc --> lê um caracter de cada vez do arquivo (se retorna EOF, acabou ou erro)
						 {
						 	printf("%c",ler);
						 }
						 
 						 rewind(fp);
						 break;
						 
				case 4 : break;
		}
			
	}while(op!=4); 
	
	fclose(fp);
}


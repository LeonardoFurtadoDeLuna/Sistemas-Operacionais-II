/*
    Name: Gravando conteúdo no arquivo.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 11 - SISTEMAS DE ARQUIVOS CONCEITOS
    Date: 07/05/2021
    Description: Programa que abre ou cria um arquivo chamado "teste" e grava três frases
*/

#include <stdio.h>
#include <string.h>

int main() 
{
	FILE *fp; // cria uma referência para um arquivo
	fp=fopen ("teste.txt","w"); // abre o arquivo --> criando acesso de gravação para um arquivo (ou arquivo é criado --> w)
	
	if (fp==NULL) 
	{
		printf ("Erro na abertura do arquivo"); // fp é um ponteiro; se retornar NULL, algo errado aconteceu
 		fclose(fp);
 		return 0;
	}
	else 
	    printf("Arquivo aberto com sucesso");

	char entrada[100];
	
	for(int i=1;i<=3;i++)
	{
		printf("\nDigite a frase %d: ",i); fflush(stdin); gets(entrada);
		strcat(entrada,"\n");
		fprintf(fp,entrada); // registra (grava) o conteúdo de uma variável no arquivo cuja referência é um ponteiro (no caso, fp)
	}
	
 	fclose(fp); // fecha o arquivo
}


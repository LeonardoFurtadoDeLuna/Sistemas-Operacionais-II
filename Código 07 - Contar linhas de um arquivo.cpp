/*
    Name: Contar linhas de um arquivo.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 11 - SISTEMAS DE ARQUIVOS CONCEITOS
    Date: 07/05/2021
    Description: Programa que conta a quantidade de linhas do arquivo especificado pelo usuário.
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
	
	fp=fopen (arq,"r");
	
	if (fp==NULL) 
	{ 
	 	printf ("Erro na abertura do arquivo"); 
 		fclose(fp);
 		return 0;
	}
	
	int total=0; 
	char entrada[100]; 
	char *c;
	printf("\nContar numero de linhas do arquivo...");
	
	while(!feof(fp)) 
	{
	 	c = fgets(entrada, 101, fp); 
	 	total++;
 	}
 	
 	printf("\nO arquivo tem %d linhas",total);
    fclose(fp);
}

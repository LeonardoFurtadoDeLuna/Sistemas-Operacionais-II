/*
    Name: Abrindo arquivo.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 11 - SISTEMAS DE ARQUIVOS CONCEITOS
    Date: 07/05/2021
    Description: Abrindo um arquivo chamado "Teste"
*/

#include <stdio.h>
main() 
{
	FILE *fp; // FILE pode ser visto como um tipo de dados e deve declarar elementos como ponteiros (referências)
	fp=fopen ("teste.txt","w"); // comando para abrir o arquivo e/ou criá-lo, dependendo do modo de uso (w = cria e abre)
	
	if (fp==NULL) 
	    printf ("\nErro na abertura do arquivo"); // se ocorrer algum erro na criação do arquivo, fp recebe NULL
	else 
	    printf("\nArquivo aberto com sucesso");
	
 	fclose(fp); // fecha o arquivo
}


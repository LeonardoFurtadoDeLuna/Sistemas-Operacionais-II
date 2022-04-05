/*
    Name: Inserir, ler e imprimir conte�do de arquivo.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 11 - SISTEMAS DE ARQUIVOS CONCEITOS
    Date: 07/05/2021
    Description: Programa que possibilita a inser��o, leitura e impress�o de conte�do de um arquivo chamado "teste"
*/

#include <stdio.h>
#include <string.h>

int main() 
{
	FILE *fp; int op; char entrada[100]; char *c;
	do
	{
		do
		{
			printf("\n1 - Criar e digitar conteudo	2 - Ler e imprimir	3 - Encerrar	--> ");
			scanf("%d",&op);
		}while(op<1 || op>3);
		
		switch(op)
		{
				case 1 : fp=fopen ("teste.txt","w");
				
						 if (fp==NULL) 
					 	 { 
						 	printf ("Erro na abertura do arquivo"); 
 							fclose(fp);
 							return 0;
						 }
						 
						 printf("\nDigite suas frases (FIM para sair): \n");
						 
						 for(;;) 
						 {
							fflush(stdin); gets(entrada);
							if(strcmp(entrada,"FIM")==0) break;
							strcat(entrada,"\n");
							fprintf(fp,entrada);
 						 }
 						 
 						 fclose(fp);
 						 break;
 						 
				case 2 : fp=fopen ("teste.txt","r"); // r = somente leitura
				
						 if (fp==NULL) 
					 	 { 
						 	printf ("Erro na abertura do arquivo"); 
 							fclose(fp);
 							return 0;
						 }
						 
						 printf("\nConteudo do arquivo: \n\n");
						 
						 while(!feof(fp)) // enquanto n�o alcan�ar o fim do arquivo...
						 {
						 	c = fgets(entrada, 101, fp); // l� uma linha com at� 100 caracteres, inclusive \n
						 	if (c) printf("%s",entrada);
 						 }
 						 
 						 fclose(fp);
 						 
				case 3 : break;
		}	
	}while(op!=3); 
}


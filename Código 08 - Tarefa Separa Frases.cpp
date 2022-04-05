/*
    Name: Tarefa separa Frases.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 13 - ARQUIVOS E SERVIDORES
    Date: 21/05/21
    Description: Correção da atividade que separa as palavras das frases de um arquivo, de modo que cada pelavra fique em uma linha.
*/

#include <stdio.h>
#include <string.h>

int main() 
{
	FILE *fp, *gp; 
	char arq[100], *c, entrada[100], texto1[100], *t; 
	int total=0, num_linha=0, conta=0;
	
	do
	{
		printf("\nDigite o nome do arquivo: ");
		fflush(stdin); gets(arq);
	}while(strlen(arq)==0);
	
	fp=fopen (arq,"r+"); 
	
	if (fp==NULL || strcmp(arq,"reserva.txt")==0) 
	{ 
	 	printf ("\nErro na abertura do arquivo\n");
 		fclose(fp);
 		return 0;
	}
	
	gp=fopen ("reserva.txt","w"); // arquivo para guardar palavras
	
	// primeira etapa: contar o número de frases
	while(!feof(fp)) 
	{
	 	c = fgets(entrada, 100, fp); // lê uma expressão com 100 caracteres, que seria o tamanho de uma linha deste arquivo
	 	if (c) printf("%d:%s",++num_linha,entrada);
	 	total++;
 	}
 	
	printf("\nNumero de frases do arquivo: %d\n",total); 
	
	// segunda etapa: criar as palavras a partir das frases e armazenar no novo arquivo
	rewind(fp);
	conta=total;
	
	while(conta>1)
	{
		c = fgets(texto1, 100, fp); 
		t = strtok(texto1," "); // pega a primeira palavra da frase
		
		while(t != NULL) // enquanto a frase não acabar (enquanto existirem palavras na frase)
	    {
    		printf("%s\n",t);
    		strcpy(entrada,t); strcat(entrada,"\n");
    		fprintf(gp,entrada);
    		t=strtok(NULL," ");
		}
	 	conta--; 
	}
	
    fclose(fp);
    fclose(gp);
    remove(arq);
    rename("reserva.txt",arq);
}

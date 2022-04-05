/*
    Name: Separa Frases 2.cpp
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
	FILE *fp, *gp; char arq[100], *c, entrada[100], texto1[100], *t; int num_linha=0;
	
	do
	{
		printf("\nDigite o nome do arquivo: "); fflush(stdin); gets(arq);
	}while(strlen(arq)==0);
	
	fp=fopen (arq,"r+"); 
	
	if (fp==NULL || strcmp(arq,"reserva.txt")==0) 
	{ 
	 	printf ("\nErro na abertura do arquivo\n"); fclose(fp);
 		return 0;
	}
	
	gp=fopen ("reserva.txt","w"); 
	
	while(!feof(fp)) 
	{
	 	c = fgets(entrada, 100, fp); 
	 	if (c) printf("%d:%s",++num_linha,entrada);
 	}
 	
	printf("\nNumero de frases do arquivo: %d\n",num_linha); 
	rewind(fp);
	
	while(num_linha>0)
	{
		c = fgets(texto1, 100, fp); t = strtok(texto1," "); 
		while(t != NULL) 
	    {
    		printf("%s\n",t);
    		strcpy(entrada,t); strcat(entrada,"\n");
    		if (strcmp(entrada,"")!=0) fprintf(gp,entrada);
    		t=strtok(NULL," ");
		}
	 	num_linha--; 
	}
	
    fclose(fp); fclose(gp);
    remove(arq);rename("reserva.txt",arq);
}

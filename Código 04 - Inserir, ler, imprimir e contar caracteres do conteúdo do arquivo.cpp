/*
    Name: Inserir, ler, imprimir e contar caracteres do conteúdo do arquivo.cpp
    Copyright: 
    Author: Prof Gerson
    Class: AULA 11 - SISTEMAS DE ARQUIVOS CONCEITOS
    Date: 07/05/2021
    Description: Programa que faz a iserção, leitura, impressão e contagem de caracteres de um arquivo chamado "teste"
*/

#include <stdio.h>
#include <string.h>

int main() 
{
	FILE *fp; int op, total; char entrada[100]; char *c, conta, ler;
	do
	{
		do
		{
			printf("\n1 - Criar e digitar conteudo	2 - Ler e imprimir	3 - Contar caracteres	4 - Encerrar	--> ");
			scanf("%d",&op);
		}while(op<1 || op>4);
		
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
						 
						 while(!feof(fp))
						 {
						 	c = fgets(entrada, 101, fp); // lê uma linha com até 100 caracteres, inclusive \n
						 	if (c) printf("%s",entrada);
 						 }
 						 
 						 fclose(fp);
 						 break;
 						 
				case 3 : fp=fopen ("teste.txt","r"); // r = somente leitura
				
						 if (fp==NULL) 
					 	 { 
						 	printf ("Erro na abertura do arquivo"); 
 							fclose(fp);
 							return 0;
						 }
						 
						 printf("\nCaractere para contar: "); fflush(stdin); conta = getchar(); total=0;
						 
						 while((ler=fgetc(fp))!=EOF) // fgetc --> lê um caracter de cada vez do arquivo (se retorna EOF, acabou ou erro)
						 {
						 	printf("%c",ler);
						 	if(conta==ler) total++;
						 }
						 
						 printf("\nNumero de caracteres %c encontrados: %d\n",conta,total);
						 fclose(fp);
						 break;
						 
				case 4 : break;
		}	
	}while(op!=4); 
}


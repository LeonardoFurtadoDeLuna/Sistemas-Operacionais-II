/*
	Name: SepararFrasesEmPalavras.cpp
	Copyright: 
	Author: leonardo.furtado
	Date: 14/05/2021 08:17
	Description: Dado um arquivo de texto, contendo frases, separar as frases palavra por palavra, 
	             deixando o novo arquivo apenas com o conte�do relativo �s palavras, sem as frases.
*/

# include <stdio.h>
# include <stdlib.h> 
# include <conio.h> 
# include <locale.h> //biblioteca de localizacao
# include <string.h> 

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp;
	int ler;
	char conteudo[300];
	
	fp=fopen ("Frase.txt","a+"); //a+ Abre para adi��o ou leitura no final do arquivo. Se o arquivo n�o existir, a fun��o o cria.
	
	if (fp==NULL) 
	{
		printf ("Erro na abertura do arquivo"); // fp � um ponteiro; se retornar NULL, algo errado aconteceu
 		fclose(fp);
 		return 0;
	}
	
	int i = 0;
	while((ler=fgetc(fp))!=EOF) // fgetc --> l� um caracter de cada vez do arquivo (se retorna EOF, acabou ou erro)
	{
		conteudo[i] = ler;
		i++;
	}
	
    for(int l=0;l<i;l++)
	{
        if(conteudo[l] == ' ')
		{
			conteudo[l] = '\n';
		}	
    }	
	
	fclose(fp);
	
	fp=fopen ("Frase.txt","w+");
	fprintf(fp,conteudo); // registra (grava) o conte�do de uma vari�vel no arquivo cuja refer�ncia � um ponteiro (no caso, fp)						
    fclose(fp);
	printf("\nAs palavras da frase foram separadas com sucesso!!! ");
	
}


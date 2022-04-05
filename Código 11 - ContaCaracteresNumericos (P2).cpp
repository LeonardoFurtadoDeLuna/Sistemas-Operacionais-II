/*
	Name: ContaCaracteresNumericos.cpp
	Copyright: 
	Author: leonardo.furtado
	Date: 28/05/2021 09:06
	Description: Crie um programa em linguagem C para contar e mostrar quantos caracteres 
	             numéricos (algarismos de 0 a 9) possui um arquivo texto no total. 
	             
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
	char ler; 
	int qtd[10];
	
	for(int i = 0; i <= 10; i++)
		qtd[i] = 0;
    
    fp=fopen ("Numeros.txt","r");
    if (fp==NULL)
    {
        printf ("Erro na abertura do arquivo");
        fclose(fp);
        return 0;
    }
    
	int i = 0;
	while((ler=fgetc(fp))!=EOF) // fgetc --> lê um caracter de cada vez do arquivo (se retorna EOF, acabou ou erro)
	{
	    if(ler=='0') 
		{
			qtd[0]++;
			i++;
		}              
	        
	    if(ler=='1')
	    {
	    	qtd[1]++;
	    	i++;
		}
	       
	    if(ler=='2')
	    {
	    	qtd[2]++;
	    	i++;
		}
	       
	    if(ler=='3')
	    {
	    	qtd[3]++;
	    	i++;
		} 
	       
	    if(ler=='4')
	    {
	    	qtd[4]++;
	    	i++;
		}
	       
	    if(ler=='5')
	    {
	    	qtd[5]++;
	    	i++;
		}
	       
	    if(ler=='6')
	    {
	    	qtd[6]++;
	    	i++;
		}
	       
	    if(ler=='7')
	    {
	    	qtd[7]++;
	    	i++;
		}
	       
	    if(ler=='8')
	    {
	    	qtd[8]++;
	    	i++;
		}
	       
	    if(ler=='9')
	    {
	    	qtd[9]++;
	    	i++;
		}
	       
	}
	
	printf("A quantidade de caracteres númericos do arquivo Numeros é de %d, sendo:"
	       "\nQtd do caracter 0 = %d  "
		   "\nQtd do caracter 1 = %d"
		   "\nQtd do caracter 2 = %d"
		   "\nQtd do caracter 3 = %d"
		   "\nQtd do caracter 4 = %d"
		   "\nQtd do caracter 5 = %d"
		   "\nQtd do caracter 6 = %d"
		   "\nQtd do caracter 7 = %d"
		   "\nQtd do caracter 8 = %d"
		   "\nQtd do caracter 9 = %d", i, qtd[0], qtd[1], qtd[2], qtd[3], qtd[4], qtd[5], qtd[6], qtd[7], qtd[8], qtd[9]);
	
}//Fim do programa

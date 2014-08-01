#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <wctype.h>
#include <modulo1.h>

// ================================= Main ================================= //
int main() // Função principal
{
	int continua=-1;
	Registro *Tpessoa = ( Registro *)malloc(sizeof( Registro));				// Cria a primeira estrutura (no) do Tpessoa, onde vai ficar armazenado a lista dos ID de todo mundo da arvore.
	if(Tpessoa == NULL)
	{
		printf("Erro de memoria (Tpessoa).\n");
		exit(1);
	}
	Tpessoa -> prox = NULL;



	while(continua != 0)
	{
		InserePessoa(Tpessoa);
		printf("'0' para parar: ");
		scanf("%d", &continua);

	}


	imprime(Tpessoa);

	system("pause");
	return 0;
}

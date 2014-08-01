#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <wctype.h>

// ================================= Estrutura ================================= //

typedef struct Reg
{
	int ID;
	struct Reg *prox;
	struct BancoDados *dados;
}Registro;

struct BancoDados
{
	char nome[30];
	char sexo;
	struct Reg *pai;
	struct Reg *filho;
	struct Reg *irmao;
	struct Reg *conjuge;
};

// ================================= Variaveis globais ================================= //

	int GeraID = -1;						//Gera ID automatico.
	struct Registro *Tpessoa = NULL;		//Iniciando ponteiro *bd global.

// ================================= Chamada Funcoes ================================= //

void InserePessoa(Registro *Tpessoa);
struct BancoDados* ProcuraIDpai();
void ImprimeListaID(Registro *Tpessoa);
void imprime (Registro *Tpessoa);

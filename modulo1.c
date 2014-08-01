#include <modulo1.h>

// ================================= Funcoes ================================= //

void InserePessoa(Registro *Tpessoa)
{
	int IDpai, IDconjuge;
	Registro *CorrePessoa= Tpessoa;

	Registro *NovoP = ( Registro *)malloc(sizeof( Registro));			// Cria um novo no que vai pro final da Lista Tpessoa.
	if(NovoP == NULL)
	{
		printf("Erro de memoria (NovoP).\n");
		exit(1);
	}

	struct BancoDados *Novobd = (struct BancoDados *)malloc(sizeof(struct BancoDados));		// Cria uma estrutura banco que vai armazenar os dados ID da pessoa acima.
	if(Novobd == NULL)
	{
		printf("Erro de memoria (Novobd).\n");
		exit(1);
	}
	NovoP->dados = Novobd;					// Linka o ponteiro do novo no com o novo Banco de dados. (TPessoa -> BancoDados).
	NovoP->ID = ++GeraID;					// Gera um ID unico e nas linhas a baixo inicializa os ponteiros, setando tudo como NULL.
	NovoP->prox = NULL;
	Novobd->pai = NULL;
	Novobd->conjuge = NULL;
	Novobd->filho = NULL;
	Novobd->irmao = NULL;

	if(GeraID == 0)							//Insere o primeiro novo No do Tpessoa (so resolve Patriarca)
	{
		CorrePessoa->prox = NovoP;
	}
	else									// Da segunda pessoa em diante, eh inserido aqui.
	{
		while(CorrePessoa->prox != NULL)	// Pesquisa pelo ultimo no e insere no final o no recem criado
		{
			CorrePessoa = CorrePessoa->prox;
		}
		CorrePessoa->prox = NovoP;
	}

	if(GeraID == 0)							// A primeira pessoa eh sempre do sexo masculino e nao tem pai, entao so precisa inserir o nome.
	{
		printf("\nNome da pessoa que vai gerar a arvore: ");
		setbuf(stdin,NULL);
		scanf("%s", &*Novobd->nome);
		Novobd->sexo = 'M';
	}
	else												// A partir da segunda pessoa em diante, so entra aqui
	{
		ImprimeListaID(Tpessoa);

		printf("Nome: ");								//Insere nome;
		setbuf(stdin,NULL);
		scanf("%s", &*Novobd->nome);

		printf("Sexo (M/F): ");							//Insere Sexo;
		setbuf(stdin,NULL);
		scanf("%c", &Novobd->sexo);

		if(Novobd->sexo == 'm' || Novobd->sexo == 'M' )		// Se for homem "M"(masculino) informa o ID do pai, mulher nao tem pai.
		{
			printf("ID do pai: ");							//Insere Pai
			scanf("%d", &IDpai);

			CorrePessoa = Tpessoa;							//Localiza o pai;
			while(CorrePessoa != NULL)
			{
				if(IDpai == CorrePessoa->ID)				//Se entrar aqui eh pq achou o pai
				{
					Novobd->pai = CorrePessoa;				//O endereco do ID pai eh passado para o ponterio *pai do Filho.
					if(CorrePessoa->dados->filho == NULL)
					{
						CorrePessoa->dados->filho = NovoP;
					}
					else									// Se o pai ja tiver um filho, entao o irmao(1o. filho do IDpai) recebe o endereco do novo irmao.
					{
						CorrePessoa->dados->filho->dados->irmao = NovoP;
					}
					break;									// sai do while.
				}
				CorrePessoa = CorrePessoa->prox;
			}
		}
		else													// Se for mulher so informa o ID do Conjuge masculino.
		{
			printf("ID do Conjuge: ");
			scanf("%d", &IDconjuge);

			CorrePessoa = Tpessoa;								//Localiza o marido;
			while(CorrePessoa != NULL)
			{
				if(IDconjuge == CorrePessoa->ID)				//Se entrar aqui eh pq achou o conjuge
				{
					if(CorrePessoa->dados->conjuge == NULL && (CorrePessoa->dados->sexo == 'm' || CorrePessoa->dados->sexo == 'M') )	// Se o marido nao tiver mulher e se o marido for do sexo masculino, casa
					{
						Novobd->conjuge = CorrePessoa;				// A mulher recebe o endereco do marido.
						CorrePessoa->dados->conjuge = NovoP;		// O marido recebe o endereco da mulher.
					}
					else
					{
						printf("\nPessoa a casada ou do mesmo Sexo!\n");	// auto explicativo.
					}
					break;
				}
				CorrePessoa = CorrePessoa->prox;
			}
		}
	}
	return;
}

void imprime(Registro *Tpessoa)					// Imprime no final o relatorio
{

	Registro *CorrePessoa = Tpessoa->prox;
			printf("\n");

	while(CorrePessoa != NULL)
	{
		printf("\n");
		printf("\n|ID: %d", CorrePessoa->ID);
		printf("\n|N: %s", CorrePessoa->dados->nome);
		printf("\n|S: %c", CorrePessoa->dados->sexo);

		if(CorrePessoa->dados->pai != NULL)
			printf("\n|P: %s", CorrePessoa->dados->pai->dados->nome);

		if(CorrePessoa->dados->conjuge != NULL)
			printf("\n|C: %s", CorrePessoa->dados->conjuge->dados->nome);


		CorrePessoa = CorrePessoa->prox;
			printf("\n");
	}

	return;
}


void ImprimeListaID(Registro *Tpessoa)				// imprime o ID e nome das pessoas antes de cada cadastro (pra verificar qual o pai ou marido);
{
	Registro *CorrePessoa= Tpessoa->prox;

	printf("\n  Pessoas Adicionadas   \n");
	while(CorrePessoa->prox != NULL)
	{
		printf("| ID: %d -> Nome: %s\n", CorrePessoa->ID, CorrePessoa->dados->nome);
		CorrePessoa = CorrePessoa->prox;
	}
	printf("\n");
	return;
}

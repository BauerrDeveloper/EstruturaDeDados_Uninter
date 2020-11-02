#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

int menu(); //função que cria o menu
void InserirMusicasNoInicio(char nomeDaMusica[], char nomeDoArtista[], float duracaoFaixa); //função que insere as musicas no inicio da playlist
void Listar();// função que lista as músicas



struct playerDeMusicas {

	char nameMusic[40];
	char nameArtist[40];
	float timeTrack;

	struct playerDeMusicas* prox;
} *Head;


int main() {

	setlocale(LC_ALL, "Portuguese"); 

	int operacao, c, loc;
	char nomeDaMusica[40];
	char nomeDoArtista[40];
	float duracaoFaixa;



	while (1) {
		operacao = menu();
		switch (operacao) {
		case 1:
			printf("Digite o nome da Música:\n ");
			gets_s(nomeDaMusica);

			printf("Digite o nome da Banda ou Artista:\n ");
			gets_s(nomeDoArtista);

			printf("Digite o tempo da faixa: \n");
			scanf_s("%f", &duracaoFaixa);


			InserirMusicasNoInicio(nomeDaMusica, nomeDoArtista, duracaoFaixa);

			break;
		case 2:
			Listar();
			break;
		case 3:
			return 0;
			break;
		default:
			printf("Opção inválida!!!!!");
			break;
		}
	}

}


int menu() {

	int op, c;
	system("Cls");

	printf("1. Inserir músicas no iníncio da playlist\n");
	printf("2. Mostrar playlist\n");
	printf("3. Sair\n");
	printf("Digite a sua escolha: ");

	scanf_s("%d", &op);
	while (((c = getchar()) != '\n' && c != EOF)) {}

	system("Cls");
	return op;
}


void InserirMusicasNoInicio(char nomeDaMusica[], char nomeDoArtista[], float duracaoFaixa) {

	playerDeMusicas* novoElemento;
	novoElemento = (struct playerDeMusicas*)malloc(sizeof(struct playerDeMusicas));
	strcpy_s(novoElemento->nameMusic, nomeDaMusica);
	strcpy_s(novoElemento->nameArtist, nomeDoArtista);
	novoElemento->timeTrack = duracaoFaixa;


	if (Head == NULL) {
		Head = novoElemento;
		Head->prox = NULL;
	}
	else {
		novoElemento->prox = Head;
		Head = novoElemento;
	}

}

void Listar() {
	char colunaNome[50] = "NOME DA MÚSICA";
	char colunaArtista[14] = "NOME DA BANDA";
	char colunaDuracao[17] = "DURAÇÃO DA FAIXA";

	playerDeMusicas* ElementoVarredura;
	ElementoVarredura = (struct playerDeMusicas*)malloc(sizeof(struct playerDeMusicas));
	ElementoVarredura = Head;

	if (ElementoVarredura == NULL) {
		printf("Nâo há musicas para na playlist \n");
		system("pause");
		return;
	}
	printf("%-50s", colunaNome);
	printf("%-20s", colunaArtista);
	printf("%-10s", colunaDuracao);
	printf("\n");

	while (ElementoVarredura != NULL) {
		printf("%-50s", ElementoVarredura->nameMusic);
		printf("%-20s", ElementoVarredura->nameArtist);
		printf("%.2f ", ElementoVarredura->timeTrack);
		ElementoVarredura = ElementoVarredura->prox;
		printf("\n");
	}
	printf("\n");
	system("pause");
	return;
}


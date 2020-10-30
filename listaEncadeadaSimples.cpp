#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int menu();
void InserirInicio(int num);
void Listar();
void InserirFim(int num);
void InserirMeio(int num, int posicao);
int Remover(int num);


struct ElementoDaLista_Simples {

	int dado; //armazenar diversos de dados de musica ao inves de dados simples
	ElementoDaLista_Simples* prox; //prox é o ponteiro q aponta pro proximo elemento da lista e tem de ser do tipo da lista e contem o proximo endereço dessa estrutura de dados
} *Head; //esse por enquanto eh o unico elemento que conhecemos da nossa lista e todos os proximos sao localizados a partir do encadeamento



int main() {

	setlocale(LC_ALL, "Portuguese");

	int op, num, pos, c;
	while (1) 	{
		op = menu();
		switch (op) {
		case 1: //inserir no inicio da lista
			printf("Digite o número desejado: ");
			scanf_s("%d", &num);
			InserirInicio(num);
			break;
		case 2://inserir no fim da lista
			printf("Digite o número desejado: ");
			scanf_s("%d", &num);
			InserirFim(num);
			break;
		case 3://inserir no meio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a posicao que deseja inserir: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			InserirMeio(num, pos);
			break;
		case 4: //remover da lista
			int res;
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(num);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
		case 5: //mostrar toda a lista
			Listar();
			break;
		case 6:
			return 0;
			break;		
		default:
			printf("Inválido\n");
			break;
		}

	}

	
}

int menu() {

	int op, c;
	system("Cls");

	printf("1. Inserir no inicio da lista encadeada simples\n");
	printf("2. Inserir no fim da lista encadeada simples\n");
	printf("3. Inserir no meio da lista encadeada simples\n");
	printf("4. Remover da lista encadeada simples\n");
	printf("5. Mostrar a lista encadeada simples\n");
	printf("6. Sair\n");
	printf("Digite a sua escolha: ");
	
	scanf_s("%d", &op);
	while (((c = getchar()) != '\n' && c != EOF)) {} //limpeza do buffer de teclado. necessario colocar apos cada scanf.

	system("Cls");
	return op;
}
	

void InserirInicio(int num) {
	ElementoDaLista_Simples *NovoElemento; //esse novo elemento é o que vamos inserir no inicio da nossa lista encadeada simples
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples)); //malloc = alocar um espaço de memoria do tamando do elemento da lista simples
	NovoElemento->dado = num; //o campo daquela struct recebe esse tipo de dado, no caso um valor numerico. A -> indica o campo da struct

	if (Head == NULL) {		//verifica se a lista esta vazia, se sim, insira no head. se não, insiro o novo elemento antes do head e o transformo no head
		Head = NovoElemento; 
		Head->prox = NULL; //o ponteiro para o proximo elemento do head recebe nulo, pois tenho somente o head na minha lista. como a lista é não circular, o fim aponta pra nulo
	}else {
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void Listar() {
	ElementoDaLista_Simples* ElementoVarredura; //inicializa um elemento de varredura
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head; // o elemento de varredura inicia no head 
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) { //enauqnto o elemento de varredura for diferente de nulo eu sei que tem alguma coisa na minha lista
		printf("%d ", ElementoVarredura->dado);  //faz um print em tela ate localiar o ultimo elemento
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}

void InserirFim(int num) { //muito semelhante a listagem. partimo do inicio ate localizar o ponteiro nulo e ele aponta pro novo elemento que eu quero inserir no final da minha lista encadeada. se a lista esta vazia o head tbm é o ultimo elemento da lista.
	ElementoDaLista_Simples* NovoElemento; 
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples)); 
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	
	NovoElemento->dado = num; // passei o dado que eu quero inserir pro novo elemento
	if (Head == NULL) { //se o head for nulo
		Head = NovoElemento; // voou inserir no head, 
		Head->prox = NULL; //que vai ser o inico e o fim
	}else {
		ElementoVarredura = Head; //se head não for nulo, faço varredura iniciando no head
		while (ElementoVarredura->prox != NULL) { // ate que o ponteiro do elemento de varredura for diferente de nulo
			ElementoVarredura = ElementoVarredura->prox; //incremento o ponteiro, passamos elemento por elemento da lista, transformo
		}
		ElementoVarredura->prox = NovoElemento;// o ponteiro do ultimo elemento que antes era nulo agora aponta para o novo elemento
		NovoElemento->prox = NULL;//e no novo elemento conterá um ponteiro nulo, pois é o ultimo elemento da lista encadeada simples e não circular
	}
}

void InserirMeio(int num, int posicao) {
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoAuxiliar; //serve para salvar o nó posterior ao que vamos inserir
	ElementoAuxiliar = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num; //

	if (posicao == 0) 	{ //verifico se é a posição 0. Se for, preciso insrerir no inicio e jogar o head pra frente
		Head = NovoElemento;
		Head->prox = NULL;
	} else { //iniciamos a varredura a procura da posição e não do ponteiro
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++) { //posição que veio como parametro no programa
			ElementoVarredura = ElementoVarredura->prox;
		}
		//quando eu chego onde preciso
		ElementoAuxiliar = ElementoVarredura->prox; // vai salvar o proximo elemento temporariamente
		ElementoVarredura->prox = NovoElemento; // elemento de varredura recebe o novo elemento
		NovoElemento->prox = ElementoAuxiliar; //novo elemento o elemento auxiliar
	}
}

int Remover(int num)
{
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* Anterior;
	Anterior = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->dado == num) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}

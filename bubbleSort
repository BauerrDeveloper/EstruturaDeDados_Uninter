#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h> //biblioteca de tempo //função de tempo que gera valores aleatorios


void BubbleSort(int vetor[]);
void BubbleSortDecrescente(int vetor[]);


#define TAMANHOVETOR 10


int main() {
    
    setlocale(LC_ALL, "portuguese");

    int vetor[TAMANHOVETOR] = { 0 }; /*quando colocamos {0} significa dizer queestou inciando todas as posições do meu vetor com valores 0 (zero).
                                   Dessa forma não é preciso fazer um laço de repetição pra iniciar o vetor*/

    srand(time(NULL));// gera uma semente aleatoria para gerarmos nosso valores aleatorios

    //INSERÇÃO DE DADOS
    for (int i = 0; i < TAMANHOVETOR; i++) {
        vetor[i] = rand() % 100; // gera valores aleatorios entre 0 e 99 utilizando a semente(baseada no horario do computador) do srand
    };

    printf("VETOR NÃO ORDENADO:\n");
    for (int i = 0; i < TAMANHOVETOR; i++) {
        printf("%d ", vetor[i]);
    };

    printf("\n");

    BubbleSort(vetor);   
    printf("VETOR ORDENADO DE FORMA CRESCENTE:\n");
    for (int i = 0; i < TAMANHOVETOR; i++) {
        printf("%d ", vetor[i]);
    };

    printf("\n");

    BubbleSortDecrescente(vetor);
    printf("VETOR ORDENADO DE FORMA DECRESCENTE:\n");
    for (int i = 0; i < TAMANHOVETOR; i++) {
        printf("%d ", vetor[i]);
    };


    printf("\n\n");

    system("pause");
    return 0;
}

//bubble sort crescente
void BubbleSort(int vetor[]) {                //foi criado uma procedure com retorno vazio chamado BubbleSort que recebe como parametro o nosso vetor que vai ser ordenado
    
    int aux;
    for (int n = 1; n <= TAMANHOVETOR; n++) { //laço externo executado igual ao tamanho do vetor
        for (int i = 0; i < (TAMANHOVETOR - 1); i++) { // laço interno vai de zero ate a ultima posicao do vetor TAMANHOVETOR-1. Aqui também fica a condicional
            if (vetor[i] > vetor[i + 1]) { //ordenação crescente. Na condicional eu comparo cada posição do vetor com a proxima. 
                aux = vetor[i]; //se a condição for verdadeira precisamos trocar os valores com o prox pra ordenar. fazems a troca usando uma variavel auxiliar que recebe o valor da posição do vetor
                vetor[i] = vetor[i + 1]; // aquela posição do vetor recebe a prox
                vetor[i + 1] = aux; // a prox recebe de volta a auxiliar
            }
        }
    }
}

void BubbleSortDecrescente(int vetor[]) {
    int aux;
    for (int n = 1; n <= TAMANHOVETOR; n++) { //laço externo executado igual ao tamanho do vetor
        for (int i = 0; i < (TAMANHOVETOR - 1); i++) { // laço interno vai de zero ate a ultima posicao do vetor TAMANHOVETOR-1. Aqui também fica a condicional
            if (vetor[i] < vetor[i + 1]) { //ordenação decrescente. Na condicional eu comparo cada posição do vetor com a proxima. 
                aux = vetor[i]; //se a condição for verdadeira precisamos trocar os valores com o prox pra ordenar. fazems a troca usando uma variavel auxiliar que recebe o valor da posição do vetor
                vetor[i] = vetor[i + 1]; // aquela posição do vetor recebe a prox
                vetor[i + 1] = aux; // a prox recebe de volta a auxiliar
            }
        }
    }
}

 #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<locale.h>

    struct cadastroAlunos {
        char nomeDoAluno[50];
        char emailAluno[50];
        int registroUniversitario;

        struct cadastroAlunos* prox;

    } *Head;

    int menu(); //cria o menu
    void inserirAluno(char nome[], char email[], int RU); //cria a função de inserir aluno passando como parametros o nome, email e ru.
    

    int main() {

        setlocale(LC_ALL, "Portuguese"); //define o idioma da aplicação para português, fazendo com que apareçam os assentos

        int operacao, c, RU;
        char nome[50];
        char email[50];

        while (1) {
            operacao = menu();
            switch (operacao) {

            case 1:

                printf_s("Insira o nome do aluno:\n ");
                gets_s(nome);


                printf_s("Insira o e-mail do aluno:\n ");
                gets_s(email);

                printf("Insira o número do registro universitário (RU) do aluno:\n ");
                scanf_s("%i", &RU);

                inserirAluno(nome, email, RU);
                break;

            case 2:
                printf_s("Digite o RU que deseja buscar:\n ");
                scanf_s("%i", &RU);
                break;
            case 3:
                return 0;

            default:
                printf_s("Comando inválido!");
                break;
            }
        }

        system("pause");
        return 0;
    }


    int menu() {
        int operacao, c;
        system("Cls");

        printf_s("#### SGAU - SISTEMA DE GESTÃO DOS ALUNOS UNINTER ####");
        printf_s("\n\n");
        printf_s("01. Cadastrar Aluno\n");
        printf_s("02. Buscar Aluno\n");
        printf_s("03. Sair\n");
        printf_s("Selecione a opção desejada:\n");
        scanf_s("%i", &operacao);

        while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer do teclado

        system("Cls");
        return operacao;

    }

    void inserirAluno(char nome[], char email[], int RU) {

        cadastroAlunos* novoElemento;
        novoElemento = (struct cadastroAlunos*)malloc(sizeof(struct cadastroAlunos)); //aloca um espaço de memória do tamanho da struct
        strcpy_s(novoElemento->nomeDoAluno, nome);
        strcpy_s(novoElemento->emailAluno, email);
        novoElemento->registroUniversitario = RU;

        if (Head == NULL) {
            Head = novoElemento;
            Head->prox = NULL;
        }
        else {
            novoElemento->prox = Head;
            Head = novoElemento;
        }



    }

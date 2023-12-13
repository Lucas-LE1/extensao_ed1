#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address {

    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[2];
    char cep[8];
    char complemento[50];

} Endereco;

typedef struct datetime {

    int dia;
    int mes;
    int ano;

} Data;

typedef struct vitima {

    char nome[50];
    char cpf[11];
    int idade;
    Endereco enderecoResidencial;
    char status_medida[20];  
    struct vitima *next;

} Vitima;

// Controlador de lista, evitar ponteiro para ponteiro
typedef struct lista {

    Vitima *inicio;
    Vitima *fim;
    int qtd;

} Lista;

void startList(Lista *lista) {

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;

}

void criarRegistro(Lista *lista) {

    Vitima *novo = (Vitima *)malloc(sizeof(Vitima));

    // Prompts
    printf("\n Digite o nome da vitima: ");
    scanf("%s", novo->nome);
    printf(" Digite seu cpf: ");
    scanf("%s", novo->cpf);
    printf(" Digite sua idade: ");
    scanf("%d", &novo->idade);
    printf(" Digite sua rua: ");
    scanf("%s", novo->enderecoResidencial.rua);
    printf(" Digite o numero: ");
    scanf("%d", &novo->enderecoResidencial.numero);
    printf(" Digite o bairro: ");
    scanf("%s", novo->enderecoResidencial.bairro);
    printf(" Digite a cidade: ");
    scanf("%s", novo->enderecoResidencial.cidade);
    printf(" Digite o estado: ");
    scanf("%s", novo->enderecoResidencial.estado);
    printf(" Digite o cep: ");
    scanf("%s", novo->enderecoResidencial.cep);
    printf(" Digite o complemento do endereço: ");
    scanf("%s", novo->enderecoResidencial.complemento);

    strcpy(novo->status_medida, "Pendente"); 
    novo->next = NULL;

    system("cls");

    if (lista->inicio == NULL) {

        lista->inicio = novo;
        lista->fim = novo;

    } else {

        lista->fim->next = novo;
        lista->fim = novo;

    }

    lista->qtd++;
}

void imprimirAtendimentosComMedidaProtetiva(Lista *lista) {

    printf("\n----- Atendimentos com Medida Protetiva -----\n");
    Vitima *atendimentoAtual = lista->inicio;

    while (atendimentoAtual != NULL) {
        printf(" Nome: %s\n", atendimentoAtual->nome);
        printf(" CPF: %s\n", atendimentoAtual->cpf);
        printf(" Idade: %d\n", atendimentoAtual->idade);
        printf(" Status da medida protetiva: %s\n", atendimentoAtual->status_medida);
        printf("------------------------------\n");

        atendimentoAtual = atendimentoAtual->next;
    }
}

int main() {

    Lista listaAtendimentos;
    startList(&listaAtendimentos);

    int opcao;

    do {

        printf("\n----- Menu -----\n");
        printf(" 1. Criar Registro\n");
        printf(" 2. Imprimir Atendimentos com Medida Protetiva\n");
        printf(" 0. Sair\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {

            case 1:

                criarRegistro(&listaAtendimentos);
                break;

            case 2:

                imprimirAtendimentosComMedidaProtetiva(&listaAtendimentos);
                break;

            case 0:

                printf(" Saindo do programa.\n");
                break;

            default:

                printf(" Opcao invalida. Tente novamente.\n");

        }
        
    } while (opcao != 0);

    return 0;
}

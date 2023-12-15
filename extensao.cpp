#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address {
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[9];
    char complemento[50];
} Endereco;

typedef struct datetime {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct vitima {
    char nome[50];
    char cpf[12];
    int idade;
    Endereco enderecoResidencial;
    char status_medida[30];
    Data data_visita; // Para registrar a data da visita
    struct vitima *next;
} Vitima;

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

    printf("\nDigite o nome da vítima: ");
    scanf("%s", novo->nome);
    printf("Digite seu CPF: ");
    scanf("%s", novo->cpf);
    printf("Digite sua idade: ");
    scanf("%d", &novo->idade);
    printf("Digite sua rua: ");
    scanf("%s", novo->enderecoResidencial.rua);
    printf("Digite o número: ");
    scanf("%d", &novo->enderecoResidencial.numero);
    printf("Digite o bairro: ");
    scanf("%s", novo->enderecoResidencial.bairro);
    printf("Digite a cidade: ");
    scanf("%s", novo->enderecoResidencial.cidade);
    printf("Digite o estado: ");
    scanf("%s", novo->enderecoResidencial.estado);
    printf("Digite o CEP: ");
    scanf("%s", novo->enderecoResidencial.cep);
    printf("Digite o complemento do endereço: ");
    scanf("%s", novo->enderecoResidencial.complemento);

    strcpy(novo->status_medida, "Medida Protetiva: Pendente");
    novo->next = NULL;
    novo->data_visita.dia = 0;
    novo->data_visita.mes = 0;
    novo->data_visita.ano = 0;

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
    printf("\n----- Atendimentos com Medida Protetiva Ativa -----\n");
    Vitima *atendimentoAtual = lista->inicio;

    while (atendimentoAtual != NULL) {
        if (strcmp(atendimentoAtual->status_medida, "Medida Protetiva: Ativa") == 0) {
            printf(" Nome: %s\n", atendimentoAtual->nome);
            printf(" CPF: %s\n", atendimentoAtual->cpf);
            printf(" Idade: %d\n", atendimentoAtual->idade);
            printf(" %s\n", atendimentoAtual->status_medida);
            printf("------------------------------\n");
        }
        atendimentoAtual = atendimentoAtual->next;
    }
}

void imprimirTodosAtendimentos(Lista *lista) {
    printf("\n----- Lista de Atendimentos -----\n");
    Vitima *atendimentoAtual = lista->inicio;

    while (atendimentoAtual != NULL) {
        printf(" Nome: %s\n", atendimentoAtual->nome);
        printf(" CPF: %s\n", atendimentoAtual->cpf);
        printf(" Idade: %d\n", atendimentoAtual->idade);
        printf(" %s\n", atendimentoAtual->status_medida);
        printf("------------------------------\n");

        atendimentoAtual = atendimentoAtual->next;
    }

    if (lista->qtd == 0) {
        printf("Nenhum atendimento registrado.\n");
    }
}

void cancelarMedidaProtetiva(Lista *lista, char cpf[]) {
    Vitima *atendimentoAtual = lista->inicio;
    int encontrou = 0;

    while (atendimentoAtual != NULL) {
        if (strcmp(atendimentoAtual->cpf, cpf) == 0) {
            strcpy(atendimentoAtual->status_medida, "Medida Protetiva: Cancelada");
            printf("Medida protetiva cancelada para: %s\n", atendimentoAtual->nome);
            encontrou = 1;
            break;
        }
        atendimentoAtual = atendimentoAtual->next;
    }

    if (!encontrou) {
        printf("Vítima com CPF %s não encontrada.\n", cpf);
    }
}

void ativarMedidaProtetiva(Lista *lista, char cpf[]) {
    Vitima *atendimentoAtual = lista->inicio;
    int encontrou = 0;

    while (atendimentoAtual != NULL) {
        if (strcmp(atendimentoAtual->cpf, cpf) == 0) {
            strcpy(atendimentoAtual->status_medida, "Medida Protetiva: Ativa");
            printf("Medida protetiva ativada para: %s\n", atendimentoAtual->nome);
            encontrou = 1;
            break;
        }
        atendimentoAtual = atendimentoAtual->next;
    }

    if (!encontrou) {
        printf("Vítima com CPF %s não encontrada.\n", cpf);
    }
}

int main() {
    Lista listaAtendimentos;
    startList(&listaAtendimentos);

    int opcao;

    do {
        printf("\n----- Menu -----\n");
        printf(" 1. Criar Registro\n");
        printf(" 2. Imprimir Atendimentos com Medida Protetiva Ativa\n");
        printf(" 3. Cancelar Medida Protetiva\n");
        printf(" 4. Ativar Medida Protetiva\n");
        printf(" 5. Imprimir Todos os Atendimentos\n");
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
            case 3:
                char cpfCancelar[12];
                printf("Digite o CPF da vítima para cancelar a medida protetiva: ");
                scanf("%s", cpfCancelar);
                cancelarMedidaProtetiva(&listaAtendimentos, cpfCancelar);
                break;
            case 4:
                char cpfAtivar[12];
                printf("Digite o CPF da vítima para ativar a medida protetiva: ");
                scanf("%s", cpfAtivar);
                ativarMedidaProtetiva(&listaAtendimentos, cpfAtivar);
                break;
            case 5:
                imprimirTodosAtendimentos(&listaAtendimentos);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

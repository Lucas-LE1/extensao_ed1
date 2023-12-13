#include <stdio.h>
#include <stdlib.h>

typedef struct address
{
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[2];
    char cep[8];
    char complemento[50];
} Endereco;

typedef struct datetime
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct vitima
{
    char nome[50];
    char cpf[11];
    int idade;
    Endereco enderecoResidencial;
    struct node *next;
} Vitima;

// controlador de lista, evitar ponteiro para ponteiro
typedef struct lista
{
    Vitima *inicio;
    Vitima *fim;
    int qtd;
} Lista;

void startList(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

void criarRegistro(Lista *lista)
{
    Vitima *novo = (Vitima *)malloc(sizeof(Vitima));
    // prompts
    printf("Digite o nome da vitima: ");
    scanf("%s", novo->nome);
    printf("Digite seu cpf: ");
    scanf("%s", novo->cpf);
    printf("Digite sua idade: ");
    scanf("%d", &novo->idade);
    printf("Digite sua rua: ");
    scanf("%s", novo->enderecoResidencial.rua);
    printf("Digite o numero: ");
    scanf("%d", &novo->enderecoResidencial.numero);
    printf("Digite o bairro: ");
    scanf("%s", novo->enderecoResidencial.bairro);
    printf("Digite a cidade: ");
    scanf("%s", novo->enderecoResidencial.cidade);
    printf("Digite o estado: ");
    scanf("%s", novo->enderecoResidencial.estado);
    printf("Digite o cep: ");
    scanf("%s", novo->enderecoResidencial.cep);
    printf("Digite o complemento do endereço: ");
    scanf("%s", novo->enderecoResidencial.complemento);

}

int main()
{

    return 0;
}
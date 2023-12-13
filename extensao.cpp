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

// estrutura fila - controlador
typedef struct queue
{
    Vitima *inicio;
    Vitima *fim;
    int qtd;
} Queue;

int main()
{

    return 0;
}
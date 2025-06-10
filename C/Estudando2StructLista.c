#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct sPessoa
{
    char nome[50];
    float valor;
} tPessoa;

typedef struct sLista
{
    tPessoa pessoa[TAM];
    int fim;
} tLista;

int cadastrar(tLista *l, float v, char n, int p)
{
    if(l->fim < (TAM - 1))
    {
        if((p >= 0) && (p <= (l->fim)))
        {
            l->fim += 1;
            for(int i = l->fim; i > p; i--)
            {
                strcpy(l->pessoa[i].nome, l->pessoa[i-1].nome);
                l->pessoa[i].valor = l->pessoa[i-1].valor;
            }
            strcpy(l->pessoa[p].nome, n);
            l->pessoa[p].valor = v;
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

int remover(tLista *l, int p)
{
    if(l->fim > -1)
    {
        if((p>=0) && (p<=(l->fim)))
        {
            for(int i = p; i <= l->fim; i++)
            {
                strcpy(l->pessoa[i].nome, l->pessoa[i+1].nome);
                l->pessoa[i].valor = l->pessoa[i+1].valor;
            }
            l->fim -= 1;
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

int main()
{
    int flag, opcao, valor, posicao, nome;
    tLista lista;
    lista.fim = -1;

    do
    {
        printf("===================MENU==================\n\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("9 - Sair\n");
        scanf("%d", &opcao); 
        switch(opcao){
            case 1:
            system("cls");
            printf("Insira o nome: ");
            gets(nome);
            printf("\nInsira o elemento na lista: ");
            scanf("%d", &valor);
            printf("\nQual a posicao? de [1] a [%d]:", lista.fim + 2 );
            scanf("%d", &posicao);
            flag = cadastrar(&lista, valor, nome, posicao);
            if (flag == 0)
            {
                printf("\nElemento inserido com sucesso!\n");
            }
            if (flag == 1)
            {
                printf("\nERRO! fila esta cheia!\n");
            }
            else
            {
                printf("\nERRO! INVALIDO!")
            }
            system("pause");
            break;

            case 2:
            system("cls");
            printf("Insira a posição do elemento que vai ser removido: ");
            scanf("%d", &posicao);
            flag = remover(&lista, posicao);
            if (flag == 0)
            {
                printf("\nElemento removido com sucesso!\n");
            }
            if (flag == 1)
            {
                printf("\nERRO! fila esta vazia!\n");
            }
            else
            {
                printf("\nERRO! INVALIDO!")
            }
            system("pause");
            break;

            case 3:
            imprimir(&lista);
            break;
        }
    }while (opcao != 9);

    return 0;
}
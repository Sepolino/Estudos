#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int cadastro(int l[], int e, int p, int *fim)
{
    if (*fim < (TAM - 1))
    {
        if ((p >= 0) && (p <= (*fim + 1)))
        {
            *fim += 1;
            for (int i = *fim; i > p; i--)
            {
                l[i] = l[i - 1];
            }
            l[p] = e;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 2;
    }
}

int remover(int l[], int p, int *fim)
{
    if (*fim > -1)
    {
        if ((p >= 0) && (p <= (*fim + 1)))
        {
            for (int i = p; i < *fim; i++)
            {
                l[i] = l[i + 1];
            }
            *fim -= 1;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 2;
    }
}

void imprimir(int l[], int fim)
{
    system("cls");
    for (int i = 0; i <= fim; i++)
    {
        printf("%d ", l[i]);
    }
    printf("\n");
    system("pause");
}

int main()
{
    int opcao, flag, elemento, posicao;
    int lista[TAM];
    int fim = -1;

    do
    {
        printf("================MENUZ=================\n\n");
        printf("1. Cadastrar\n");
        printf("2. Remover\n");
        printf("3. Imprimir\n");
        printf("9. Sair\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                system("cls");
                printf("Insira um elemento na lista: ");
                scanf("%d", &elemento);
                printf("\nInsira a posicao do elemento: de [0] a [%d]", fim + 1);
                scanf("%d", &posicao);
                flag = cadastro(lista, elemento, posicao, &fim);
                if(flag == 0)
                {
                    system("cls");
                    printf("Elemento inserido com sucesso!!!!!!!!!!\n\n");
                    system("pause");
                }
                if(flag == 1)
                {
                    system("cls");
                    printf("TA CHEIOKK\n\n");
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                printf("\nQual a posicao do elemento para remover: de [0] a [%d]", fim + 1);
                scanf("%d", &posicao);
                flag = remover(lista, posicao, &fim);
                if(flag == 0)
                {
                    system("cls");
                    printf("Elemento removido com sucesso!!!!!!!!!!\n\n");
                    system("pause");
                }
                if(flag == 1)
                {
                    system("cls");
                    printf("TA CHEIOKK\n\n");
                    system("pause");
                }
                break;
            case 3:
                imprimir(lista, fim);
                break;
        }
    } while (opcao != 9);

    return 0;
}

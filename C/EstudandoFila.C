#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int push(int f[], int e, int *fim)
{
    if(*fim < (TAM - 1))
    {
        *fim = *fim + 1;
        f[*fim] = e;
        return 0;
    }
    else
    {
        return 1;
    }
}

int pop(int f[], int *fim)
{
    if(*fim > -1)
    {
        for(int i = 0; i <= *fim; i++)
        {
            f[i] = f[i + 1];
        }
        *fim = *fim - 1;
        return 0;
    }
    else
    {
        return 1;
    }
}

void imprimir(int f[], int fim)
{
    system("cls");
    for(int i = 0; i <= fim; i++)
    {
        printf("%d ",f[i]);
    }
    system("pause");
}

int main()
{
    int fila[TAM];
    int flag, opcao, valor;
    int fim;
    fim = -1;

    do
    {
        printf("===========MENU==========\n\n");
        printf("1 . Push\n");
        printf("2 . Pop\n");
        printf("3 . Imprimir\n");
        printf("9 . Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Insira um valor no push: ");
            scanf("%d", &valor);
            flag = push(fila, valor, &fim);
            if (flag == 0)
            {
                system("cls");
                printf("Elemento inserido com sucesso na fila!\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("ERRO A fila ESTA CHEIA\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            flag = pop(fila, &fim);
            if (flag == 0)
            {
                system("cls");
                printf("Elemento removido com sucesso na fila!\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("ERRO A fila ESTA VAZIA\n");
                system("pause");
            }
            break;
        case 3:
            imprimir(fila, fim);
            break;
        }

    } while (opcao != 9);
    
    return 0;
}
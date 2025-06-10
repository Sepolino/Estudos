#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int push(int p[], int v, int *t)
{
    if (*t < (TAM - 1))
    {
        *t = *t + 1;
        p[*t] = v;
        return 0;
    }
    else
    {
        return 1;
    }
}

int pop(int p[], int *t)
{
    if (*t > -1)
    {
        *t = *t - 1;
        return 0;
    }
    else
    {
        return 1;
    }
}

void imprimir(int p[], int t)
{
    system("cls");
    printf("===========PILHA==========\n\n");
    for (int i = t; i >= 0; i--)
    {
        printf("%d\n", p[i]);
    }
    system("pause");
}

int main()
{
    int pilha[TAM];
    int flag, opcao, valor;
    int topo = -1;

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
            flag = push(pilha, valor, &topo);
            if (flag == 0)
            {
                system("cls");
                printf("Elemento inserido com sucesso na pilha!\n");
                system("pause");
            }
            if (flag == 1)
            {
                system("cls");
                printf("ERRO A PILHA ESTA CHEIA\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            flag = pop(pilha, &topo);
            if (flag == 0)
            {
                system("cls");
                printf("Elemento removido com sucesso na pilha!\n");
                system("pause");
            }
            if (flag == 1)
            {
                system("cls");
                printf("ERRO A PILHA ESTA VAZIA\n");
                system("pause");
            }
            break;
        case 3:
            imprimir(pilha, topo);
            break;
        }

    } while (opcao != 9);
}
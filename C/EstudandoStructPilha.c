#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct sPilha
{
    int valor[TAM];
    int topo;
} tPilha;

int push(tPilha *p, int v)
{
    if(p->topo < (TAM - 1))
    {
        p->topo += 1;
        p->valor[p->topo] = v;
        return 0;
    }
    else
    {
        return 1;
    }
}

int pop(tPilha *p)
{
   if(p->topo > -1)
    {
        p->topo -= 1;
        return 0;
    }
    else
    {
        return 1;
    } 
}

void imprimir(tPilha *p)
{
    system("cls");
    for(int i = p->topo; i >= 0; i--)
    {
        printf("%d\n", p->valor[i]);
    }
    printf("\n");
    system("pause");
}

int main()
{
    tPilha pilha;
    int flag, opcao, valor;
    pilha.topo = -1;


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
            flag = push(&pilha, valor);
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
            flag = pop(&pilha);
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
            imprimir(&pilha);
            break;
        }

    } while (opcao != 9);
}
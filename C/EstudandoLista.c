#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct {
    int fim;
    int elemento[TAM];
} lista;

int push(lista *l, int valor)
{
    if(l->fim < (TAM - 1)){
        l->fim += 1;
        l->elemento[l->fim] = valor;
        return 0;
    }
    else{
        return 1;
    }

}

int pop(lista *l, int posicao)
{
    if(l->fim > -1){
    	posicao -= 1;
        for(int i = posicao; i <= l->fim; i++)
        {
            l->elemento[i] = l->elemento[i + 1];
		}
        l->fim -= 1;
        return 0;
    }
    else{
        return 1;
    }
}

void imprimir(lista *l)
{
    system("cls");
    printf("===============LISTA=============\n\n");
    for(int i = 0; i <= l->fim; i++)
    {
        printf("%d ", l->elemento[i]);
    }
    printf("\n");
    system("pause");
    
}


int main()
{
    int flag, opcao, valor, posicao;
    lista lista;
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
            printf("Insira o elemento na lista: ");
            scanf("%d", &valor);
            flag = push(&lista, valor);
            if (flag == 0)
            {
                printf("\nElemento inserido com sucesso!\n");
            }
            else
            {
                printf("\nERRO! fila esta cheia!\n");
            }
            system("pause");
            break;

            case 2:
            system("cls");
            printf("Insira a posição do elemento que vai ser removido: ");
            scanf("%d", &posicao);
            flag = pop(&lista, posicao);
            if (flag == 0)
            {
                printf("\nElemento removido com sucesso!\n");
            }
            else
            {
                printf("\nERRO! fila esta vazia!\n");
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